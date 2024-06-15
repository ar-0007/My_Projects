#include <iostream>
#include <string>
#include <map>
using namespace std;

// A simple chat bot class that uses a map of keywords and responses
class ChatBot {
private:
/Z/ A map of keywords and responses
map<string, string> responses;

public:
// A constructor that initializes the responses map
ChatBot() {
responses["hello"] = "Hello, I am a chat bot.";
responses["how are you"] = "I am fine, thank you.";
responses["what is your name"] = "My name is ChatBot.";
responses["what can you do"] = "I can answer different types of questions.";
responses["what is c++"] = "C++ is a programming language.";
responses["bye"] = "Goodbye, have a nice day.";
// Added questions and answers about ChatGPT
responses["what is chatgpt"] = "ChatGPT is a neural network model that can generate natural language responses.";
responses["how does chatgpt work"] = "ChatGPT uses a transformer architecture that learns from a large corpus of conversational data.";
responses["who made chatgpt"] = "ChatGPT was made by researchers from Microsoft Research and University of Montreal.";
// Added questions and answers about programming
responses["what is a variable"] = "A variable is a name that refers to a value stored in memory.";
responses["what is a loop"] = "A loop is a way of repeating a block of code multiple times with different conditions.";
responses["what is a function"] = "A function is a block of code that performs a specific task and can be reused in different places.";
responses["what is a class"] = "A class is a blueprint that defines the attributes and behaviors of an object.";
 responses["what is a pointer"] = "A pointer is a variable that stores the memory address of another variable.";
    responses["what is an array"] = "An array is a collection of elements of the same data type, accessed by an index.";
    responses["what is object-oriented programming"] = "Object-oriented programming is a programming paradigm that organizes code into objects with attributes and behaviors.";
    responses["what is recursion"] = "Recursion is a programming technique where a function calls itself to solve a problem.";
    responses["what is artificial intelligence"] = "Artificial intelligence is the simulation of human intelligence processes by machines.";
    responses["what is a database"] = "A database is a structured collection of data, organized for efficient storage and retrieval.";
    responses["what is version control"] = "Version control is a system that manages changes to code, allowing multiple people to collaborate on projects.";
    responses["what is open source"] = "Open source refers to software that is publicly accessible and can be freely used, modified, and shared.";
   responses["what's the weather like today"] = "I'm sorry, I don't have access to real-time data. You can check a weather website or app for current conditions.";
    responses["how do I make a cup of coffee"] = "To make a cup of coffee, boil water, add coffee grounds to a filter, pour hot water over the grounds, and let it steep for a few minutes.";
    responses["what's a good book to read"] = "A great book recommendation would be 'To Kill a Mockingbird' by Harper Lee.";
    responses["how can I stay motivated"] = "Staying motivated can be challenging. Setting goals, staying organized, and taking breaks can help.";
    responses["what's a simple workout routine"] = "A simple workout routine could include 30 minutes of brisk walking, 15 minutes of bodyweight exercises, and 10 minutes of stretching.";
    responses["how do I cook pasta"] = "Boil water, add salt, put in pasta, cook until al dente (firm), drain, and mix with your favorite sauce.";
    responses["what's a good way to manage stress"] = "Practicing deep breathing, meditation, exercise, and spending time in nature can help manage stress.";
    responses["how do I start learning a musical instrument"] = "Start with the basics and practice regularly. You can find tutorials online or consider taking lessons.";
}

// A method that takes a user input and returns a response
string respond(string input) {
// Convert the input to lowercase
for (int i = 0; i < input.length(); i++) {
input[i] = tolower(input[i]);
}

// Check if the input matches any keyword in the map
if (responses.find(input) != responses.end()) {
// Return the corresponding response
return responses[input];
} else {
// Return a default response
return "Sorry, I don't understand.";
}
}
};

// A main function that creates a chat bot object and interacts with the user
int main() {
// Create a chat bot object
ChatBot bot;

// Greet the user
cout << "Welcome to the chat bot program.\n";
cout << "You can ask me different types of questions.\n";
cout << "Type 'bye' to end the conversation.\n";

// Declare a variable to store the user input
string input;

// Start a loop to get the user input and respond
while (true) {
// Get the user input
cout << "\nYou: ";
getline(cin, input);

// Check if the user wants to end the conversation
if (input == "bye") {
break;
}

// Respond to the user input
cout << "Bot: " << bot.respond(input) << "\n";
}

// End the program
return 0;
}


