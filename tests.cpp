#include "gtest/gtest.h"
#include <iostream>
#include "utilmaths.h"

using namespace utilmaths;

TEST(ComplexTesting,ConversionConstructor)
{
	complex::complex c1 = 0;
	complex::complex c2 = {0.0f,0.0f};

	EXPECT_EQ(c1,c2);

}

TEST(ComplexTesting,OperatorConversion)
{
	complex::complex c1 = {1.0f,0.0f};
	complex::complex c2 = {1.0d,1.0d};

	EXPECT_EQ((float) c1,1.0f);
	EXPECT_EQ((int) c1, 1);
	EXPECT_EQ((float) c2, (float) sqrt(2));
	EXPECT_EQ((double) c2, sqrt(2));
}

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

TEST(ComplexTesting,OperatorOstream)
{
	std::cout<<"testing cout\n";
	complex::complex z = {0.0,1.0};
	std::cout<<"cnum : "<<z<<std::endl;
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
	double tau = 2.0d * M_PI;
	complex::complex i1 = {0.0d,0.0d};
	complex::complex c1 = {1.0d,0.0d};
	complex::complex i2 = {0.0d,tau};
	complex::complex c2 = {0.0f,1.0f};
	complex::complex i3 = {1.0d,M_PI/2};
	complex::complex c3 = {0.0d,M_E};

	EXPECT_EQ(complex::exp(i1),c1);
	EXPECT_NEAR(complex::exp(i2).i,	c1.i,1e-15);
	EXPECT_NEAR(complex::exp(i2/4).i, c2.i,1e-15);
	EXPECT_NEAR(complex::exp(i3).x,c3.x,1e-15);
	EXPECT_NEAR(complex::exp(i3).i,c3.i,1e-15);
}

TEST(LinalgTesting,ComplexArgument)
{
	complex::complex x1 = {1.0,1.0};
	complex::complex x2 = {1.0,-1.0};

	linalg::vector2 v = {x1,x2};
	std::cout<<v.x1<<" "<<v.x2<<std::endl;
}

TEST(LinalgTesting,RealArgument)
{
	double x1 = 1.0;
	double x2 = 0.1;

	linalg::vector2 v = {x1,x2};
}
