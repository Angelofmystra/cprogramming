#include <stdio.h>
int main()
{
    printf("AI.\n");
    return 0;
}
// Perceptrons are the easiest datastructure to learn for the study of Neural Networking
// It has a number of external input links, one internal input (called a bias), a threshold, and one output link. 
// Usually the input values are Boolean
// The output of the perceptron is always a Boolean
// When the output is on (has the value 1) it is said to be firing
// This comes from biology
// All of the inputs (including the bias) have weights attached to the input line that modify the input value.
// The weight is just multipled with the input, so if the input value was 4
// and the weight was -2, the weighted input value would be -8
// the Threshold is one of the key components of a perceptron
// It determines, baesd on the inputs, whether the perceptron fires or not
// Basically it takes all the weighted input values and sums. if the sum is above or equal to some value (called the Threshold), then the percepton fires
// Traditionally the Threshold is represented by a symbol Theta (a square-like S)
// The main feature of a perceptron is that they can be trained (or learn) to behave a certain way
// One popular beginner assignment is to have a perceptron model a basic boolean function such as AND or OR
// Perception learning is guided, that is, you have to have something to imitate. 
// It products an output, compare it to what the output should be, and then adjusts itself a little bit. After repeating this cycle enough times, the perception is said to have converged ( a technical name for learned) to correct the behaviour
// This learning method is called the delta rule, because of the way the perceptron checks its accuracy.
// The difference between the perceptron's output and the correct output is assigned the letter delta, and the Weight i for Input i is altered like this 
// (the i shows that the change is separate for each Weight, and each weight has its corresponding input)
// Change in Weight i = Current Value of Input i x (Desired Output - Current Output)
// This is elegantly summed upto:
// w_i = x_i.d
