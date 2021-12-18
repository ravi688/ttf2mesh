
#include <ttf2mesh.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{

	const char* file_path = "resource/fonts/arial.ttf";

	ttf_t* font = NULL;
	ttf_load_from_file(file_path, &font, false);
	assert(font != NULL);

	int index = ttf_find_glyph(font, L'R');
	assert(index >= 0);

	ttf_mesh_t *mesh;
    int result = ttf_glyph2mesh(&font->glyphs[index], &mesh, TTF_QUALITY_NORMAL, TTF_FEATURES_DFLT);
	assert(result == TTF_DONE);

	printf("Vertex count: %u\n", mesh->nvert);
	for(int i = 0; i < mesh->nvert; i++)
	{
		printf("(%f, %f)\n", mesh->vert[i].x, mesh->vert[i].y);
	}


    ttf_free_mesh(mesh);

	puts("Exited with 0");
	return 0;
}