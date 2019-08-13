#version 450 core

in  vec2            texture_coords;

out vec4            color;

uniform sampler2D   Texture;

uniform vec4        user_color;

void main()
{
    vec4 sampled_color = texture(Texture, texture_coords);
    color = vec4(sampled_color.x + user_color.x, sampled_color.y + user_color.y,
                 sampled_color.z + user_color.z, sampled_color.w * user_color.w);
}
