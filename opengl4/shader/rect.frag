 #version 330 core
   
   out vec4 FragColor;

    in vec2 TexCoord;

    uniform sampler2D ourTexture;
	uniform sampler2D ourTexture2;

    void main()
    {
     FragColor = mix(texture2D(ourTexture, TexCoord),texture2D(ourTexture2, TexCoord),0.2);
    }
