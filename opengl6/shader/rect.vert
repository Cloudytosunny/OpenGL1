        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;
		layout (location = 2) in vec3 aNormal;
        out vec2 TexCoord;
		out vec3 Normal;
		out vec3 FragPos;
		
		uniform mat4 transform = mat4(1.0f);
		
		uniform mat4 model = mat4(1.0);
		uniform mat4 view = mat4(1.0);
		uniform mat4 projection = mat4(1.0);
        void main()
        {
             //gl_Position=transform * vec4(aPos, 1.0f);
			gl_Position =projection * view * model * vec4(aPos, 1.0f);
            TexCoord = aTexCoord;
			FragPos = vec3(model * vec4(aPos, 1.0));
			Normal = mat3(transpose(inverse(model))) * aNormal;
        }