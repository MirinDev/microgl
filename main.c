#include <main.h>

Frame* frame;
ZFrame* z_frame;

Frame* texture;

mat4 project_m;
mat4 view_m;
mat4 model_m;

char data[256] = "     $$$$$          $$$$$$$$$       ***@@*@        *@*@@@*@@@      *@**@@@*@@@     **@@@@****        @@@@@@@        **$***         ***$**$***     ****$$$$****    @@*$@$$@$*@@    @@@$$$$$$@@@    @@$$$$$$$$@@      $$$  $$$       ***    ***     ****    ****  ";

vertice interpolate_vertice(vertice** verts, vec3 interpolate)
{
    vec3 v3[3] = {verts[0]->v, verts[1]->v, verts[2]->v};
    vec2 u3[3] = {verts[0]->u, verts[1]->u, verts[2]->u};
    vec3 n3[3] = {verts[0]->n, verts[1]->n, verts[2]->n};

    return (vertice){interpolate_v3(v3, interpolate), interpolate_v2(u3, interpolate), interpolate_v3(n3, interpolate)};
}

vec4 vsshader(void* data)
{
    vertice* vert = (vertice*)data;
    mat4 proj = mul_m4(project_m, view_m);

    return mul_v4_m4(proj, mul_v4_m4(model_m, v3_to_v4(vert->v, 1)));
}

char fsshader(void* data, vec3 interpolate)
{
    vertice** verts = (vertice**)data;
    vertice vert = interpolate_vertice(verts, interpolate);
    
    return Texture(texture, vert.u);
}

int main(int argc, char* argv[]){
    init();

    frame = create_frame(64, 32);
    z_frame = create_zframe(64, 32);

    texture = create_frame_data(data, 16, 16);

    model_m = identity(1);
    view_m = translate(identity(1), (vec3){0, 0, -2});
    project_m = project(1, DEGTORAD(90.0), 0.1, 100);

    bool gameloop = true;
    while (gameloop)
    {
        int key = getch();
        switch (key)
        {
            case 'q':
                gameloop = false;
                break;
        }

        model_m = rotate_y(model_m, DEGTORAD(0.01));

        clear_frame(frame, ' ');
        clear_zframe(z_frame);
        fill_triangles(frame, z_frame, model, sizeof(vertice), model_inds, sizeof(model_inds)/sizeof(*model_inds), vsshader, fsshader);

        present_frame(frame);

        usleep(1);
    }

    delete_frame(texture);
    delete_zframe(z_frame);
    delete_frame(frame);
    quit();

    return 0;
}
