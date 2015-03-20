#include "stdafx.h"

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowApi) : ClosedPolyline(_windowApi)
{
}

Polygon::~Polygon()
{
}

void Polygon::add(const Point& _point)
{
	if (getPoints().size() >= 2)
	{
		if (isOnPreviousLine(_point))
			throw runtime_error("Deux points sur la même ligne!");
		if (crossesPreviousLines(_point))
			throw runtime_error("Un segment du polygone en croise un autre!");
	}

	ClosedPolyline::add(_point);
}

bool Polygon::isOnPreviousLine(const Point& _point) const
{
	if (getPoints().size() < 2) throw runtime_error("Ligne précédente inexistante");

	Point prevPoint = getPoints().at(getPoints().size() - 2);
	Point nextPoint = getPoints().back();

	/****************************************************************************
	Prenons la droite suivante:

	      /C    où:
	     /      A = prevPoint
	   B/       B = _point
	   /        C = nextPoint
	A /

	1) Regardons si le point B se situe sur la droite qui passe par AC

	D'abords, on regarde si la pente de A à C est la même que celle de B à C :
	    (C.x - A.x)   (C.x - B.x)
	    ----------- = -----------
	    (C.y - A.y)   (C.y - B.y)

	Afin d'éviter les nombres décimaux (on ne veut pas de perte de précision),
	on regarde si le produit des extrêmes est égale au produit des moyens:
	    (C.x - A.x) * (C.y - B.y) = (C.x - B.x) * (C.y - A.y)

	Si c'est égale, les points A ,B et C sont tous sur la même droite
	(Donc AC et BC sont parallèles).
	***************************************************************************/

	/*
	Rappel définition colinéaire (de Antidote V8):
	    Qui a la même direction et est situé sur la même droite.
	*/
	bool pointEstSurDroite = isColineaire(prevPoint, _point, nextPoint);

	/****************************************************************************
	2) Vérifions ensuite si le point se situe sur le même segment.
	(car contrairement à une droite, un segment n'est pas infini.
	Un segment est délimité par 2 points).

	Pour faire ça, on vérifie si les les valeurs de x et y se situe entre les
	valeurs de x et y des 2 points qui l'entoure.
	****************************************************************************/

	bool pointEstSurSegment = false;
	if (pointEstSurDroite)
	{
		pointEstSurSegment = isBetween(prevPoint.x, _point.x, nextPoint.x) &&
			isBetween(prevPoint.y, _point.y, nextPoint.y);
	}

	// Si les 2 conditions sont respectées, le point est sur le même segment.
	return pointEstSurDroite && pointEstSurSegment;
}

bool Polygon::crossesPreviousLines(const Point& _point) const
{
	/*
	Le segment CD est le segment à en devenir du polygone si aucun segment se croise.
	On va tester ce segment contre tous les autres segments du polygone afin de
	déterminer si il croise au moins un segment de celui-ci;
	*/

	Point C = getPoints().back();
	Point D = _point;

	for (auto it = getPoints().begin(); next(it) < getPoints().end(); ++it)
	{
		// On regarde si le segment CD croise un des segments AB du polygone.
		Point A = *it;
		Point B = *next(it);

		if (intersectsSegment(A, B, C, D))
			return true;
	}

	return false;
}

bool Polygon::isColineaire(const Point& _previousPoint, const Point& _currentPoint, const Point& _nextPoint) const
{
	// Retourne vrai si les trois points sont sur la même droite
	double resultat1 = (_nextPoint.x - _previousPoint.x) * (_nextPoint.y - _currentPoint.y);
	double resultat2 = (_nextPoint.y - _previousPoint.y) * (_nextPoint.x - _currentPoint.x);

	/*
	Puisqu'on utilise des doubles, on doit faire attention lorsqu'on fait
	des comparaisons.

	Voir les commentaires de la méthode areNearlyEqual.
	*/
	return areNearlyEqual(resultat1, resultat2);
}

bool Polygon::intersectsSegment(const Point& _A, const Point& _B, const Point& _C, const Point& _D) const
{
	/****************************************************************************

	On a le segment AB, et le segment CD. On veut savoir s'ils se croisent.

	Comment?

	La théorie en question provient d'un professeur en Computer Science de
	la prestigieuse université Berkeley: https://www.cs.cmu.edu/~quake/robust.html

	Je vais essayer d'expliquer la théorie de ce professeur (car la page est un peu
	vide...).

	-----

	On a 4 matrices de points:

	1)               2)               3)               4)
	Ax Ay | 1        Ax Ay | 1        Ax Ay | 1        Bx By | 1
	Bx By | 1        Bx By | 1        Cx Cy | 1        Cx By | 1
	Cx Cy | 1        Dx Dy | 1        Dx Dy | 1        Dx Dy | 1

	(On est techniquement en 3 dimensions, on ajoute une rangée de '1'
	afin qu'on puisse faire les calculs qui vont suivre. Ça donne un volume,
	mais ce volume est l'équivalent de son périmètre en 2D, car '1' n'affecte pas
	le résultat). Je crois...

	Il y a 4 matrices, car je compare chaque point d'un segment avec
	les deux points d'un autre segment, soit:
	    - Le point C avec le segment AB
	    - Le point D avec le segment AB
	    - Le point A avec le segment CD
	    - Le point B avec le segment CD

	On calcule ensuite le déterminant de chaque matrice :

	      Det1                  Det2
	1)    | Ax-Cx  Bx-Cx |      | Ax-Dx  Bx-Dx |
	      | Ay-Cy  By-Cy |  vs  | Ay-Dy  By-Dy |

	      Det3                  Det4
	2)    | Cx-Ax  Dx-Ax |      | Cx-Bx  Dx-Bx |
	      | Cy-Ay  Dy-Ay |  vs  | Cy-By  Dy-By |

	Pourquoi? On veut déterminer si un point est à gauche ou à droite
	d'un segment. Pour ça il faut savoir son orientation face au segment/vecteur
	en question (est-il à gauche ou à droite du segment ou sur le segment).
	Le signe du déterminant détermine l'orientation du volume résultant.

	On comprend mieux avec un schéma :

	       C
	       |
	       |
	A--------------B
	       |
	       |
	       D

	Je regarde si le point A se situe à gauche ou à droite du point C et D.
	Je regarde ensuite si le point B se situe à gauche ou à droite du point
	C et D.

	- Si un point est à gauche d'un segment, le déterminant de la matrice sera > 0
	- Si un point est à droite d'un segment, le déterminant de la matrice sera < 0
	- Si un point est sur le segment, le déterminant de la matrice sera 0 ***

	    *** Je ne vérifie pas cette condition dans cette fonction. Je m'en occupe déjà avec
	    ma fonction isColineaire (qui est appelée avant intersectsSegment avant l'ajout
	    d'un point au polygone, et qui vérifie justement que le point ajouté ne se situe pas
	    sur la ligne précédente. Elle est aussi moins couteuse.).

	Pour que le segment CD croise le segment AB, un des 4 scénarios suivants
	doit être vrai:
	    1) A est gauche du point C, et B est à droite du point C.
	        -> ( det1  et -det2 )  et ( det3  et -det4 )
	    2) A est à droite du point C, et B est gauche du point C.
	        -> (-det1  et  det2 )  et ( det3  et -det4 )
	    3) B est à gauche du point D, et A est à droite du point D.
	        -> ( det3  et -det4 )  et ( det1  et -det2 )
	    4) B est à droite du point D, et A est à gauche du point D.
	        -> (-det3  et  det4 ) et  ( det1  et -det2 )

	Si aucun scénario correspond au résultat, la droite CD ne croise pas
	la droite AB.

	****************************************************************************/


	// Calcul des déterminants
	double det1 = (_A.x - _C.x) * (_B.y - _C.y) - (_B.x - _C.x) * (_A.y - _C.y);
	double det2 = (_A.x - _D.x) * (_B.y - _D.y) - (_B.x - _D.x) * (_A.y - _D.y);

	double det3 = (_C.x - _A.x) * (_D.y - _A.y) - (_D.x - _A.x) * (_C.y - _A.y);
	double det4 = (_C.x - _B.x) * (_D.y - _B.y) - (_D.x - _B.x) * (_C.y - _B.y);

	// Comparaison avec les 4 scénarios 
	if ((det1 > 0 && det2 < 0) && (det3 > 0 && det4 < 0))
	{
		return true;
	}

	if ((det1 < 0 && det2 > 0) && (det3 < 0 && det4 > 0))
	{
		return true;
	}

	if ((det1 > 0 && det2 < 0) && (det3 < 0 && det4 > 0))
	{
		return true;
	}

	if ((det1 < 0 && det2 > 0) && (det3 > 0 && det4 < 0))
	{
		return true;
	}

	// Aucun croisement
	return false;
}


bool Polygon::isBetween(const double& _a, const double& _b, const double& _c) const
{
	// On vérifie de deux manières, afin de gérer les nombres négatifs.
	// Retourne vrai si _b se situe entre _a et _c
	return _a <= _b && _b <= _c || _c <= _b && _b <= _a;
}

bool Polygon::areNearlyEqual(const double& _a, const double& _b) const
{
	/*
	Ici j'établie une "marge d'erreur" afin d'établir si un chiffre égale à 0.
	Car comparer des doubles n'est pas la même chose qu'avec des entiers.

	Sinon, cette fonction peut ne pas retourner un résultat véridique (car avec
	des doubles, des fois 0 != 0).

	Plus d'information ici: http://stackoverflow.com/q/13698927
	et ici http://realtimecollisiondetection.net/blog/?p=89
	*/

	return fabs(_a - _b) < numeric_limits<double>::epsilon();
}