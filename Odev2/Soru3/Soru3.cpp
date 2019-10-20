#include <iostream>
#include <glm.hpp>
#include <vector>

using namespace std;
using namespace glm;

vec3 Projection(glm::vec3* e, glm::vec3* e_prime, int& i)
{
	int k = 0;
	vec3 result;
	result.x = 0;
	result.y = 0;
	result.z = 0;
	while (k < i - 1)
	{
		float e_prime_k_squared = glm::dot(e_prime[k], e_prime[k]);
		result += ((glm::dot(e[i], e_prime[k]) / e_prime_k_squared) * e_prime[k]);
		k++;
	}

	return result;
}
int main()
{
	const int n = 3;  // Vektor sayisi
	vec3 e[] = {
	vec3(sqrt(2) / 2, sqrt(2) / 2, 0),
	vec3(-1, 1, -1),
	vec3(0, -2, -2)
	};

	vec3 e_prime[n];
	e_prime[0] = e[0];  // Adim A

	int i = 0;  // Adim B

	do  // Adim C
	{
		e_prime[i] = e[i] - Projection(e, e_prime, i);

		i++;    // Adim D
	} while (i < n);

	for (int i = 0; i < n; i++)
	{
		std::cout << "Vector e_prime_" << i + 1 << ": < "
			<< e_prime[i].x << ", "
			<< e_prime[i].y << ", "
			<< e_prime[i].z << " >" << std::endl;
	}

	return 0;

}