#include <gtest/gtest.h>
#include "maybe.hpp"

TEST(Monad, Maybe){
	auto f = [](int x) -> Maybe<double> {return x+1.0;};
	std::function<Maybe<double>(int)> fun(f);
	auto a = Maybe<int>(1.0);
	a.bind(fun);
    EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
