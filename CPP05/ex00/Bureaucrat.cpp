#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << *this << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.getName()), grade(copy.getGrade())
{}

void        Bureaucrat::incGrade(void)
{
    --grade < 1 ? throw GradeTooHighException() : 0;
}

void        Bureaucrat::decGrade(void)
{
    ++grade > 150 ? throw GradeTooLowException() : 0;
}

std::string Bureaucrat::getName(void) const
{
    return (name);
}

int         Bureaucrat::getGrade(void) const
{
    return (grade);
}

Bureaucrat::~Bureaucrat()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Too High Grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Too Low Grade");
}

std::ostream& operator << (std::ostream& cout, const Bureaucrat& b)
{
    return (cout << b.getName() << ", bureaucrat grade " << b.getGrade());
}