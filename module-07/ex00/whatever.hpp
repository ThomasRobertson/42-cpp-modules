#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &A, T &B)
{
	T temp = A;
	A = B;
	B = temp;
}

template<typename T>
T min(T A, T B)
{
	if (A < B)
		return B;
	else
		return A;
}

template<typename T>
T max(T A, T B)
{
	if (A > B)
		return B;
	else
		return A;
}

#endif // !WHATEVER_HPP