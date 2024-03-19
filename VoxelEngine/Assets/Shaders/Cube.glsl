#type vertex
#version 460 core

layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec2 aTexCoord;

//out vec2 TexCoord;

uniform mat4 u_Transform;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
  gl_Position = u_Projection * u_View * u_Transform * vec4(aPos, 1.0);
  //TexCoord = aTexCoord;
}

#type fragment
#version 460 core

out vec4 FragColor;

//in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
  //FragColor = texture(texture1, TexCoord);
  FragColor = vec4(0.0f,1.0f,0.0f,1.0f);
}