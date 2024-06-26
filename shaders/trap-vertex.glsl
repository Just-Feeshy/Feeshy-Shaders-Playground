attribute vec2 a_position;
attribute vec3 a_color;

varying vec4 v_color;

void main() {
    gl_Position = vec4(a_position, 0.0, 1.0);
    v_color = vec4(floor(a_color), 1.0);
}
