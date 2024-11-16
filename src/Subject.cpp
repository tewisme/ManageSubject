#include "Subject.h"
#include <iostream>
#include <utility>


Subject::Subject ()
= default;

auto Subject::operator=(const Subject& rhs) const -> Subject
{
	return rhs;
}

std::string Subject::getName ()
const
{
				return name;
}

std::string Subject::getPoint4 ()
const
{
				return point4;
}

int Subject::getCredits ()
const
{
				return cre;
}

int Subject::getSemester ()
const
{
				return sem;
}

double Subject::getPoint ()
const
{
				return point;
}

void Subject::chngName (std::string newName)
{
				name = std::move(newName);
}

void Subject::chngPoint (const double newPoint)
{
				point = newPoint;
}

void Subject::chngCredits (const int newCre)
{
				cre = newCre;
}

void Subject::chngSemester (const int newSem)
{
				sem = newSem;
}

void Subject::chngPoint4 (const std::string& newP)
{
				point4 = newP;
}

