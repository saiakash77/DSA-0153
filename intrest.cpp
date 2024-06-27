#include &lt;iostream&gt;
// Function to calculate simple interest for senior citizen
float calculateInterestSenior(float principal, float rate, float time) {
return (principal * rate * time) / 100;
}
// Function to calculate simple interest for other customers
float calculateInterest(float principal, float time) {
float rate = 10.0; // Default rate for other customers
return (principal * rate * time) / 100;
}
int main() {
float principal, time, interest;
std::cout &lt;&lt; &quot;Enter principal amount: &quot;;
std::cin &gt;&gt; principal;
std::cout &lt;&lt; &quot;Enter time period (in years): &quot;;
std::cin &gt;&gt; time;
char customerType;
std::cout &lt;&lt; &quot;Are you a senior citizen? (Y/N): &quot;;
std::cin &gt;&gt; customerType;
if (customerType == &#39;Y&#39; || customerType == &#39;y&#39;) {
interest = calculateInterestSenior(principal, 12.0, time);
} else {
interest = calculateInterest(principal, time);
}
std::cout &lt;&lt; &quot;Simple interest: &quot; &lt;&lt; interest &lt;&lt; std::endl;

return 0;
}
