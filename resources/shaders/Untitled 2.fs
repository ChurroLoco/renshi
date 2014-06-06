uniform float time;
uniform sampler2D tex;
uniform sampler2D tex2;
void main()
{
	vec4 new_coord = gl_TexCoord[0];
	new_coord.y = (new_coord.y + sin((new_coord.x + (time * 0.1)) * 5.0) * 0.15);
	new_coord.x = (new_coord.x + sin((new_coord.y - (time * 0.1)) * 5.0) * 0.15);

	vec4 new_coord2 = gl_TexCoord[0];
	new_coord2.y = (new_coord2.y - sin((new_coord2.x - (time * 0.1)) * 5.0) * 0.15);
	new_coord2.x = (new_coord2.x - sin((new_coord2.y + (time * 0.1)) * 5.0) * 0.15);

	gl_FragColor = gl_Color * texture2D(tex, new_coord.xy) * texture2D(tex2, new_coord2.xy);
}
