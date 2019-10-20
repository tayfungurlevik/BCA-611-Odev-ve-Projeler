#include <iostream>
#include <glm.hpp>
#include <vector>
using namespace glm;
using namespace std;
int main()
{
	//Vertexler
	vec3 V1, V2, V3, V4, V5, V6, V7, V8;
	vector<vec3> vertexler;
	//Vertextleri birlestiren kenarlar
	vec3 E1, E2, E3, E4, E5, E6, E7, E8;
	vector<vec3> kenarVektorler;
	//Vertexlerin degerleri 
	V1.x = 20.f; V1.y = 20.f;
	vertexler.push_back(V1);
	V2.x = 80.f; V2.y = 20.f;
	vertexler.push_back(V2);
	V3.x = 80.f; V3.y = 40.f;
	vertexler.push_back(V3);
	V4.x = 60.f; V4.y = 40.f;
	vertexler.push_back(V4);
	V5.x = 60.f; V5.y = 60.f;
	vertexler.push_back(V5);
	V6.x = 40.f; V6.y = 60.f;
	vertexler.push_back(V6);
	V7.x = 40.f; V7.y = 40.f;
	vertexler.push_back(V7);
	V8.x = 20.f; V8.y = 40.f;
	vertexler.push_back(V8);
	cout << "Vertex listesi" << endl;
	for (size_t i = 0; i < vertexler.size(); i++)
	{
		cout << "Vertex" << i + 1 <<": "<<vertexler[i].x<<","<<vertexler[i].y<< endl;
	}
	for (size_t i = 0; i < vertexler.size() - 1; i++)
	{
		kenarVektorler.push_back(vertexler[i + 1] - vertexler[i]);
	}
	kenarVektorler.push_back(vertexler[0] - vertexler[vertexler.size() - 1]);

	vector<float> zCrossProducts;
	for (size_t i = 0; i < kenarVektorler.size()-1; i++)
	{
		zCrossProducts.push_back(cross(kenarVektorler[i], kenarVektorler[i + 1]).z);
	}
	zCrossProducts.push_back(cross(kenarVektorler[kenarVektorler.size() - 1],kenarVektorler[0]  ).z);
	cout << "Vektorel carpimlarin z bilesenleri" << endl;
	for (size_t i = 0; i < zCrossProducts.size(); i++)
	{
		cout << zCrossProducts[i] << endl;
	}
	bool disbukey = false;
	for (size_t i = 0; i < zCrossProducts.size()-1; i++)
	{
		if ((zCrossProducts[i + 1] * zCrossProducts[i]) > 0)
			disbukey = true;
		else
		{
			disbukey = false;
			break;
		}
			
	}
	if (disbukey)
	{
		cout << "Polygon disbukey" << endl;
	}
	else
	{
		cout << "Polygon icbukey" << endl;
	}
	return 0;
}