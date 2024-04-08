
void main(void) {
	float colorR = mod(gl_FragCoord.x / 100.0, 1.0);
	float colorG = mod(gl_FragCoord.y / 100.0, 1.0);
	float colorB = 0.5; // Static value for simplification

	gl_FragColor = vec4(colorR, colorG, colorB, 1.0);
}
