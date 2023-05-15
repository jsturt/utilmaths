#include "gtest/gtest.h"
#include "utilmaths.h"

using namespace utilmaths;

//TEST(ComplexTesting,ArgsFloatDouble)
//{
//	complex::complex c1 = {1.0f,1.0d};
//}

TEST(ComplexTesting,OperatorPlus)
{
	complex::complex c1 = {1,1};
	complex::complex c2 = {0,1};
	complex::complex c3 = {1,2};

	complex::complex c4 = {0.0f,0.0f};

	EXPECT_EQ(c1+c2,c3);
	EXPECT_EQ(c1+c4,c1);
}

TEST(ComplexTesting,OperatorMinus)
{
	complex::complex c1 = {1,1};
	complex::complex c2 = {0,1};
	complex::complex c3 = {1,0};

	complex::complex c4 = {0.0f,1.0f};

	EXPECT_EQ(c1-c2,c3);
	EXPECT_EQ(c1-c4,c3);
}

TEST(ComplexTesting,OperatorTimes)
{
	complex::complex c1 = {3,7};
	complex::complex c2 = {0,2};
	complex::complex c3 = {-14,6};
	complex::complex c4 = {2,3};
	complex::complex c5 = {-15,23};

	complex::complex c6 = {0.f,2.f};

	EXPECT_EQ(c1*c2,c3);
	EXPECT_EQ(c1*c4,c5);

	EXPECT_EQ(c1*c6,c3);
}

TEST(ComplexTesting,OperatorDivide)
{
	complex::complex c1 = {4.0f,6.0f};
	complex::complex c2 = {4.0f,2.0f};
	complex::complex c3 = {1.4f,0.8f};

	complex::complex c4 = {4,2};

	EXPECT_EQ(c1/c2,c3);
	EXPECT_EQ(c1/c4,c3);
}

TEST(ComplexTesting,OperatorScalarDivisionLHS)
{
	complex::complex c1 = {2.0f,5.0f};
	complex::complex c2 = {1.0f,2.5f};
	EXPECT_EQ(c1/2.0f,c2);
	EXPECT_EQ(c1/2,c2);
}

TEST(ComplexTesting,OperatorScalarTimesLHS)
{
	complex::complex c1 = {3,7};
	complex::complex c2 = {1,1};
	complex::complex c3 = {0,0};

	complex::complex z1 = {6,14};
	complex::complex z2 = {2,2};
	complex::complex z3 = {0,0};

	EXPECT_EQ(2*c1,z1);
	EXPECT_EQ(2.0f*c2,z2);
	EXPECT_EQ(5*c3,z3);
}

TEST(ComplexTesting,OperatorScalarTimesRHS)
{
	complex::complex c1 = {3,7};
	complex::complex c2 = {1,1};
	complex::complex c3 = {0,0};

	complex::complex z1 = {6,14};
	complex::complex z2 = {2,2};
	complex::complex z3 = {0,0};

	EXPECT_EQ(c1*2,z1);
	EXPECT_EQ(c2*2.0f,z2);
	EXPECT_EQ(c3*5,z3);
}

TEST(ComplexTesting,OperatorEquals)
{
	complex::complex c1 = {-6.0f,2.0f};
	complex::complex c2 = {7.0f,11.0f};

	complex::complex c3 = {1,2};

	c1=c2;
	c3=c2;

	EXPECT_EQ(c1,c2);

	EXPECT_EQ(c2,c3);
}

TEST(ComplexTesting,OperatorPlusEquals)
{
	complex::complex c1 = {3,7};
	complex::complex c2 = {1,1};
	complex::complex c3 = {4,8};

	complex::complex c4 = {1.0f,1.0f};
	complex::complex c5 = {3,7};

	c1 += c2;
	c5 += c4;

	EXPECT_EQ(c1,c3);
	EXPECT_EQ(c5,c3);
}

TEST(ComplexTesting,OperatorTimesEquals)
{
	complex::complex c1 = {3,7};
	complex::complex c2 = {4,2};
	complex::complex c3 = {-2,34};

	complex::complex c4 = {3.0f,7.0f};

	c1 *= c2;
	c4 *= c2;

	EXPECT_EQ(c1,c3);

	EXPECT_EQ(c4,c3);
}

TEST(ComplexTesting,OperatorScalarTimesEquals)
{
	complex::complex c1 = {9.2f,3.14f};
	complex::complex c2 = {18.4f,6.28f};

	c1 *= 2;

	EXPECT_EQ(c1,c2);
}

TEST(ComplexTesting,OperatorDivideEquals)
{
	complex::complex c1 = {4.0f,6.0f};
	complex::complex c2 = {4.0f,2.0f};
	complex::complex c3 = {1.4f,0.8f};

	complex::complex c4 = {4,6};

	c1 /= c2;
	c4 /= c2;

	EXPECT_EQ(c1,c3);
	// integer division always causes issues
	//EXPECT_EQ(c4,c3);

}

TEST(ComplexTesting,OperatorScalarDivideEquals)
{
	complex::complex c1 = {4.0f,16.0f};
	complex::complex c2 = {2.0f,8.0f};

	c1 /= 2;

	EXPECT_EQ(c1,c2);
}

TEST(ComplexTesting,OperatorEqualsEquals)
{
	complex::complex c1 = {1,1};
	complex::complex c2 = {0,1};
	complex::complex c4 = {1,1};

	complex::complex c5 = {0.0d,0.0d};
	complex::complex c6 = {0.0f,0.0f};

	EXPECT_EQ(c1,c4);
	EXPECT_EQ(c1,c1);
	EXPECT_NE(c1,c2);

	EXPECT_EQ(c5,c6);
}

TEST(ComplexTesting,OperatorNotEquals)
{
	complex::complex c1 = {4,1};
	complex::complex c2 = {1,1};
	complex::complex c3 = {1,1};
	
	complex::complex c4 = {2.0f,4.2f};
	complex::complex c5 = {4.0f,1.0f};

	EXPECT_TRUE(c1!=c2);
	EXPECT_FALSE(c2!=c3);

	EXPECT_TRUE(c1!=c4);
	EXPECT_FALSE(c1!=c5);
}

TEST(ComplexTesting,OperatorLessEqualTo)
{
	complex::complex c1	= {1,1};
	complex::complex c2 = {1,2};
	complex::complex c3 = {1,2};

	complex::complex c4 = {0.1f,0.1f};

	EXPECT_TRUE(c1<=c2);
	EXPECT_TRUE(c2<=c3);
	EXPECT_FALSE(c2<=c1);

	EXPECT_TRUE(c4<=c1);
}

TEST(ComplexTesting,OperatorGreaterEqualTo)
{
	complex::complex c1	= {1,1};
	complex::complex c2 = {1,2};
	complex::complex c3 = {1,2};

	complex::complex c4 = {2.0f,2.1f};

	EXPECT_TRUE(c2>=c1);
	EXPECT_TRUE(c2>=c3);
	EXPECT_FALSE(c1>=c2);

	EXPECT_TRUE(c4>=c1);
}

TEST(ComplexTesting,OperatorLessThan)
{
	complex::complex c1 = {1,1};
	complex::complex c2 = {2,2};

	complex::complex c3 = {0.1f,0.1f};

	EXPECT_TRUE(c1<c2);
	EXPECT_FALSE(c2<c1);

	EXPECT_TRUE(c3<c1);
}

TEST(ComplexTesting,OperatorGreaterThan)
{
	complex::complex c1 = {1,1};
	complex::complex c2 = {2,2};

	complex::complex c3 = {2.0f,1.5f};

	EXPECT_FALSE(c1>c2);
	EXPECT_TRUE(c2>c1);

	EXPECT_TRUE(c3>c1);
}

TEST(ComplexTesting,FunctionConj)
{
	complex::complex c1 = {1,-1};
	complex::complex c2 = {1,1};

	EXPECT_EQ(complex::conj(c1),c2);
}

TEST(ComplexTesting,FunctionMod)
{
	complex::complex c1 = {7,5};

	EXPECT_EQ(complex::mod(c1),8);
}

TEST(ComplexTesting,FunctionisReal)
{
	complex::complex c1 = {7.2f,0.0f};
	complex::complex c2 = {0.0f,3.1f};

	EXPECT_TRUE(complex::isReal(c1));
	EXPECT_FALSE(complex::isReal(c2));
}

TEST(ComplexTesting,FunctionExp)
{
	float theta = 0.0f;
	float tau = 2.0f * M_PI;
	complex::complex c1 = {1.0f,0.0f};
	complex::complex c2 = {0.0f,1.0f};
	complex::complex c3 = -1*c2;

	EXPECT_EQ(complex::exp(theta),c1);
	EXPECT_EQ(complex::exp(tau),	c1);
	//EXPECT_EQ(complex::exp(M_PI), c2);
	//EXPECT_EQ(complex::exp(-M_PI),c3); 

}

/*

	 how do I want to use these utilities?
	 having to do utilmaths::complex::complex cnum = {1,1}; would be a bit much maybe?
	 even if we do :

	 using namespace utilmaths
	 complex::complex cnum = {1,1};
	 if(complex::isReal(cnum))
	 {
			std::cout<<"it's real!\n";
	 }

	 that is a little verbose?

	 without the complex namespace and wrapping methods such as isReal() and conj()
	 into the struct gives the following:

	 using namespace utilmaths;
	 complex cnum = {1,1};
	 if(cnum.isReal())
	 {
			std::cout<<"it's real!\n";
	 }
*/ 

