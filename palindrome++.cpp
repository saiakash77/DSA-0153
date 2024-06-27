#include &lt;iostream&gt;
int main()
{
int number, originalNumber, reversedNumber = 0, remainder;
std::cout &lt;&lt; &quot;Enter a number: &quot;;
std::cin &gt;&gt; number;
originalNumber = number; // Store the original number for comparison
while (number &gt; 0) {
remainder = number % 10;
reversedNumber = reversedNumber * 10 + remainder;
number /= 10;

}

if (originalNumber == reversedNumber) {
std::cout &lt;&lt; &quot;The number is a palindrome.&quot; &lt;&lt; std::endl;
} else {
std::cout &lt;&lt; &quot;The number is not a palindrome.&quot; &lt;&lt; std::endl;
}
return 0;
}
