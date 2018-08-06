#version 330 core

layout (location = 0) out vec4 position;

in DATA {
	vec4 position;
	vec4 color;
} fs_in;

void main
{
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	// color = color * intensity;
	color = fs_in.color * intensity;
}
