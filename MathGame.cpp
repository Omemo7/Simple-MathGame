#include<iostream>
#include<string>
using namespace std;
enum enDifficulty { Easy = 1, Med, Hard, MixDiff };
enum enOpType { Add = 1, Sub, Mul, Div, MixOp };
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}
int ReadNumberInRange(string Message, int From, int To)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < From || Number>To);
	return Number;
}
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
int GetOperands(enDifficulty QuestionDifficulty)
{
	if (QuestionDifficulty == Easy)
		return RandomNumber(0, 9);
	else if (QuestionDifficulty == Med)
		return RandomNumber(10, 50);
	else if (QuestionDifficulty == Hard)
		return RandomNumber(51, 100);
	else
		return RandomNumber(0, 100);
}
string GetOperation(enOpType& OpType, int Number1, int Number2)
{
	string strNumber1 = to_string(Number1);
	string strNumber2 = to_string(Number2);
	if (OpType == MixOp)
		OpType = (enOpType)RandomNumber(1, 4);
	if (OpType == Add)
		return strNumber1 + " + " + strNumber2 + "= ";
	else if (OpType == Sub)
		return strNumber1 + " - " + strNumber2 + "= ";
	else if (OpType == Mul)
		return strNumber1 + " * " + strNumber2 + "= ";
	else if (OpType == Div)
		return strNumber1 + " / " + strNumber2 + "= ";

}
int GetResult(enOpType OpType, int Number1, int Number2)
{
	if (OpType == Add)
		return Number1 + Number2;
	else if (OpType == Sub)
		return Number1 - Number2;
	else if (OpType == Mul)
		return Number1 * Number2;
	else if (OpType == Div)
		return Number1 / Number2;
}
void QuestionScreen(int NumberOfActiveQuestion, int NumberOfQuestions, enDifficulty QuestionDifficulty, enOpType OpType, int& CountOfRight, int& CountOfWrong)
{
	int Answer;
	int Number1 = GetOperands(QuestionDifficulty);
	int Number2 = GetOperands(QuestionDifficulty);
	cout << "Question [" << NumberOfActiveQuestion << "/" << NumberOfQuestions << "]\n";
	cout << GetOperation(OpType, Number1, Number2) << endl;
	cin >> Answer;
	if (Answer == GetResult(OpType, Number1, Number2))
	{
		cout << "Right answer :-)\n";
		CountOfRight++;
	}
	else
	{
		cout << "Wrong answer :-(\n";
		cout << "The right answer is: " << GetResult(OpType, Number1, Number2) << endl;
		CountOfWrong++;
	}

}
void QuestionsLoop(int NumberOfQuestions, enDifficulty QuestionDifficulty, enOpType OpType, int& CountOfRight, int& CountOfWrong)
{
	for (int i = 1; i <= NumberOfQuestions; i++)
	{
		cout << "\n_____________________________________________________\n";
		QuestionScreen(i, NumberOfQuestions, QuestionDifficulty, OpType, CountOfRight, CountOfWrong);
		cout << "\n_____________________________________________________\n";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int CountOfRight = 0, CountOfWrong = 0;
	int NumberOfQuestions = ReadPositiveNumber("How many questions do you want?");
	enDifficulty QuestionDifficulty = (enDifficulty)ReadNumberInRange("Difficulty is:[1]Eazy,[2]Med,[3]Hard,[4]Mix: ", 1, 4);
	enOpType OpType = (enOpType)ReadNumberInRange("Operating Type is:[1]Add,[2]Sub,[3]Mul,[4]Div,[5]Mix: ", 1, 5);
	QuestionsLoop(NumberOfQuestions, QuestionDifficulty, OpType, CountOfRight, CountOfWrong);
	cout << endl << "Number of right: " << CountOfRight << endl;
	cout << "Number of wrong: " << CountOfWrong << endl;
	if (CountOfRight >= CountOfWrong)
		cout << "Pass\n";
	else
		cout << "Fail\n";

	return 0;
}