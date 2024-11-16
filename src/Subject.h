#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <utility>

class Subject
{
private:
				std::string name, point4{"D"};
				int cre{}, sem{};
				double point{0};
public:
				Subject ();
				explicit Subject (std::string nm) : name (std::move(nm)){};
				auto operator =(const Subject& rhs) const -> Subject;;
				[[nodiscard]] std::string getName () const;
				[[nodiscard]] std::string getPoint4 () const;
				[[nodiscard]] int getCredits () const;
				[[nodiscard]] int getSemester () const;
				[[nodiscard]] double getPoint () const;
				void chngName (std::string newName);
				void chngPoint (double newPoint);
				void chngCredits (int newCre);
				void chngSemester (int newSem);
				void chngPoint4 (const std::string&);
};

#endif
