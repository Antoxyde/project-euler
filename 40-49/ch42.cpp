#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

#define T(n) 0.5 * n * (n + 1)

std::string find_max_word(std::vector<std::string> strings) {
	for (const std::string& str : strings) {
		std::cout << str << std::endl;
	}
	
	return "";
}

int main(void) {
	// Roadmap
	// * Pour chaque mot dans le fichiers
	// 		* On calcule son poids
	// 		* Si il est supérieur a la plus grande valeur des nombres triangles qu'on a calculer, on en calcule plus
	// 		* une fois qu'il est inférieur, on regarde si il est dedans
	// 		* si il est dedans, on incrémente
	
	std::string line;

	std::ifstream file("p042_words.txt");

	if (file.is_open()) {
		getline(file, line
	}

	

	find_max_word(lines);

}
