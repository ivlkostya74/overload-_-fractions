// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Fraction
{
private:
	int numerator_=1;
	int denominator_ = 1;
	
	int HCF(int numerator, int denominator)
	{
		if (numerator < 0)numerator *= -1;
		if (denominator < 0)denominator *= -1;




		while (numerator > 0 && denominator > 0)
		{

			if ((numerator > denominator) )
				numerator %= denominator;
			else denominator %= numerator;
		}
		return  numerator+ denominator;
	}



	

public:
	Fraction()=default;
	Fraction(int numerator, int denominator)

	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator + (const Fraction& other)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ * other.denominator_) + (other.numerator_ * this->denominator_);
		rezult.denominator_ = (this->denominator_ * other.denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;
	}
	Fraction operator - (const Fraction& other)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_);
		rezult.denominator_ = (this->denominator_ * other.denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;
	}


	Fraction operator * (const Fraction& other)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ * other.numerator_);
		rezult.denominator_ = (this->denominator_ * other.denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;
	}

	Fraction operator / (const Fraction& other)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ * this->denominator_);
		rezult.denominator_ = (this->denominator_ * other.numerator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;
	}
	Fraction operator ++ () 
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ + this->denominator_);
		rezult.denominator_ = (this->denominator_ );
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;

	}

	Fraction operator ++ (int)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ + this->denominator_);
		rezult.denominator_ = (this->denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;

	}
	Fraction operator -- ()
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ + this->denominator_);
		rezult.denominator_ = (this->denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;

	}

	Fraction operator -- (int)
	{
		Fraction rezult;
		rezult.numerator_ = (this->numerator_ + this->denominator_);
		rezult.denominator_ = (this->denominator_);
		int nod = HCF(rezult.numerator_, rezult.denominator_);
		rezult.numerator_ /= nod;
		rezult.denominator_ /= nod;
		return rezult;

	}

	friend std::ostream& operator <<(std::ostream& ostr, const Fraction& fraction);
};

std::ostream& operator <<(std::ostream& ostr, const Fraction& fraction)
{
	if (fraction.denominator_ == 1) {
		ostr << fraction.numerator_;
	}
	else {
		ostr << fraction.numerator_ << "/" << fraction.denominator_;
	}
	return ostr;
}


int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");


	int numerator1=0;
	int denominator1=1;
	int numerator2 =0;
	int denominator2 =1;
	

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);


	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
	std::cout << "++f1 = " << ++f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "--f1 = " << --f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f2++ = " << f1 << " * " << ++f2 << " = " << f1 * f2 << std::endl;
	std::cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << std::endl;
	std::cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << std::endl;
	std::cout << "f2 = " << f2 << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
