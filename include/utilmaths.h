#pragma once
#define _USE_MATH_DEFINES
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
			complex(T _x, T _i) : x{_x}, i{_i} {};
			complex(T z) : x{z}, i{z} {};
			template<arithmetic R>
			explicit operator R() const {return static_cast<R>(mod(*this));}

			template<arithmetic R>
			complex 	operator+(const complex<R> &rhs)	const {return {x+rhs.x, i+rhs.i};}
			template<arithmetic R>
			complex 	operator-(const complex<R> &rhs)	const {return {x-rhs.x, i-rhs.i};}
			template<arithmetic R>
			complex 	operator*(const complex<R> &rhs) 	const {return {((x*rhs.x)-(i*rhs.i)), ((x*rhs.i)+(i*rhs.x))};}
			complex 	operator*(const T &rhs) 					const {return {rhs * x, rhs * i};}
			template<arithmetic R>
			complex 	operator/(const complex<R> &rhs) 	const {return (*this * conj(rhs))/(rhs * conj(rhs)).x;}
			complex 	operator/(const T &rhs) 					const {return {x/rhs, i/rhs};}
			friend complex 	operator*(const T &lhs, 		const complex &rhs) {return {lhs * rhs.x, lhs * rhs.i};}

			template<arithmetic R>
			complex& 	operator=(const complex<R> &rhs) 		{x=static_cast<T>(rhs.x); i=static_cast<T>(rhs.i); return *this;}
			template<arithmetic R>
			complex&	operator+=(const complex<R> &rhs)		{x+=static_cast<T>(rhs.x); i+=static_cast<T>(rhs.i); return *this;}
			template<arithmetic R>
			complex&	operator*=(const complex<R> &rhs)		{*this=*this * rhs; return *this;}
			complex&	operator*=(const T &rhs)						{*this=*this * rhs; return *this;}
			template<arithmetic R>
			complex&	operator/=(const complex<R> &rhs)		{*this=*this / rhs; return *this;}
			complex&	operator/=(const T &rhs)						{*this=*this / rhs; return *this;}
			
			template<arithmetic R>
			bool 			operator==(const complex<R> &rhs) 	const {return (x==rhs.x && i==rhs.i);}
			template<arithmetic R>
			bool 			operator!=(const complex<R> &rhs) 	const {return (x!=rhs.x || i!=rhs.i);}			
			template<arithmetic R>
			bool 			operator<=(const complex<R> &rhs)		const {return mod(*this)<=mod(rhs);}
			template<arithmetic R>
			bool 			operator>=(const complex<R> &rhs)		const	{return mod(*this)>=mod(rhs);}
			template<arithmetic R>
			bool 			operator<(const complex<R> &rhs)		const	{return mod(*this)<mod(rhs);}
			template<arithmetic R>
			bool 			operator>(const complex<R> &rhs)		const	{return mod(*this)>mod(rhs);}
		};
		
		template<arithmetic T>
		const complex<T> 	conj(const complex<T> &z) 	{return {z.x,-z.i};}
		template<arithmetic T>
		const T 					mod(const complex<T> &z) 		{return sqrt((z * conj(z)).x);}
		template<arithmetic T>
		const bool 				isReal(const complex<T> &z) {return z.i==0;}
		template<arithmetic T>
		const complex<T> 	exp(const complex<T> &z)		{return {(T)(std::exp(z.x)*cos(z.i)),(T)(std::exp(z.x)*sin(z.i))};}
	}

	namespace linalg{

	}
}
