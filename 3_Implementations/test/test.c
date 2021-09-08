#include "unity.h"
#include "game.h"

#define PROJECT_NAME    "TIC TAC TOE"

void setUp()
{
    

}

void tearDown()
{

}

void test_successfullWin()
{
    char arr[10]={'0','x','x','x','o','x','o','o','o','x'};
     TEST_ASSERT_EQUAL(1, checkWinner());
}
void test_successfuldraw()
{
    char arr[10]={'0','o','x','o','o','x','o','x','o','x'};
    TEST_ASSERT_EQUAL(0,checkWinner());
}
void test_Emptyboard()
{
    char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
    TEST_ASSERT_EQUAL(-1,checkWinner());
}
int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_successfullWin);
  RUN_TEST(test_successfuldraw);
  RUN_TEST(test_Emptyboard);
  return UNITY_END();
}
