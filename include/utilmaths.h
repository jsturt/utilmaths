#pragma once
#include <cmath>
#include <concepts>
#include <type_traits>

namespace utilmaths{
	template<typename T>
	concept arithmetic = std::signed_integral<T> or std::floating_point<T>;
	
	namespace complex{
		template<arithmetic T>
		struct complex
		{
			T x;
			T i;
			complex 	operator+(const complex &rhs)	const {return {x+rhs.x, i+rhs.i};}
			complex 	operator-(const complex &rhs)	const {return {x-rhs.x, i-rhs.i};}
			complex 	operator*(const complex &rhs) const {return {((x*rhs.x)-(i*rhs.i)), ((x*rhs.i)+(i*rhs.x))};}
			complex 	operator*(const T &rhs) 			const {return {rhs * x, rhs * i};}
			complex 	operator/(const complex &rhs) const {return (*this * conj(rhs))/(rhs * conj(rhs)).x;}
			complex 	operator/(const T &rhs) 			const {return {x/rhs, i/rhs};}
			friend complex 	operator*(const T &lhs, const complex &rhs) {return {lhs * rhs.x, lhs * rhs.i};}
			// test this
			//friend complex 	operator/(const T &lhs, const complex &rhs) {return {lhs / rhs.x, lhs / rhs.i};}

			complex& 	operator=(const complex &rhs) 			{if(this != &rhs) {x=rhs.x; i=rhs.i;} return *this;}
			complex&	operator+=(const complex &rhs)			{x+=rhs.x; i+=rhs.i; return *this;}
			complex&	operator*=(const complex &rhs)			{*this=*this * rhs; return *this;}
			complex&	operator*=(const T &rhs)						{*this=*this * rhs; return *this;}
			complex&	operator/=(const complex &rhs)			{*this=*this / rhs; return *this;}
			complex&	operator/=(const T &rhs)						{*this=*this / rhs; return *this;}

			bool 			operator==(const complex &rhs) 	const {return (x==rhs.x && i==rhs.i);}
			bool 			operator!=(const complex &rhs) 	const {return (x!=rhs.x || i!=rhs.i);}			
			bool 			operator<=(const complex &rhs)	const {return mod(*this)<=mod(rhs);}
			bool 			operator>=(const complex &rhs)	const	{return mod(*this)>=mod(rhs);}
			bool 			operator<(const complex &rhs)		const	{return mod(*this)<mod(rhs);}
			bool 			operator>(const complex &rhs)		const	{return mod(*this)>mod(rhs);}
		};
		
		template<arithmetic T>
		const complex<T> 	conj(const complex<T> &z) 	{return {z.x,-z.i};}
		template<arithmetic T>
		const T 					mod(const complex<T> &z) 		{return sqrt((z * conj(z)).x);}
		template<arithmetic T>
		const bool 				isReal(const complex<T> &z) {return z.i==0;}
	}

	namespace linalg{

	}
}
