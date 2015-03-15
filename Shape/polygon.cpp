#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowApi): ClosedPolyline(_windowApi)
{
}

Polygon::~Polygon()
{
	
}

void Polygon::add(Point& _point)
{
	if (points.size() >= 2 && isOnPreviousLine(points.at(points.size() - 2), _point, points.back()))
			throw runtime_error("Deux points sur la même ligne!");

	ClosedPolyline::add(_point);
	
}

bool Polygon::isOnPreviousLine(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const
{
	/****************************************************************************
	Prenons la droite suivante:

	      /C    où:
	     /      A = _previousPoint
	   B/       B = _currentPoint
	   /        C = _nextPoint
	A /

	1) Regardons si la droite qui passe par AC est parallèle à la
	   droite qui passe par BC.
	
	D'abords, on regarde si la pente de A à C est la même que celle de B à C :
	    (C.x - A.x)   (C.x - B.x)
		----------- = -----------
		(C.y - A.y)   (C.y - B.y)

	Afin d'éviter les nombres décimaux (on ne veut pas de perte de précision), 
	on regarde si le produit des extrêmes est égale au produit des moyens:
	    (C.x - A.x) * (C.y - B.y) = (C.x - B.x) * (C.y - A.y)

	Si c'est égale, la droite qui passe par AC est parallèle à la
	droite qui passe par BC.
	***************************************************************************/

	bool droiteEstParallele = (_nextPoint.x - _previousPoint.x) * (_nextPoint.y - _currentPoint.y) == (_nextPoint.y - _previousPoint.y) * (_nextPoint.x - _currentPoint.x);

	/**************************************************************************** 
	2) Vérifions ensuite si le point se situe sur le même segment.
	   (car contrairement à une droite, un segment n'est pas infinie.
	   Un segment est délimité par 2 points).

	   Pour faire ça, on vérifie si les les valeurs de x et y se situe entre les
	   valeurs de x et y des 2 points qui l'entoure.
	****************************************************************************/

	bool pointEstSurSegment = false;
	if (droiteEstParallele)
	{
		pointEstSurSegment = isBetween(_previousPoint.x, _currentPoint.x, _nextPoint.x) &&
			isBetween(_previousPoint.y, _currentPoint.y, _nextPoint.y);
	}

	// Si les 2 conditions sont respectées, le point est sur le même segment.
	return droiteEstParallele && pointEstSurSegment;
}

bool Polygon::isBetween(const double& _a, const double& _b, const double& _c) const
{
	//On vérifie de deux manières, afin de gérer les nombres négatifs. 
	return _a <= _b && _b <= _c || _c <= _b && _b <= _a;
}