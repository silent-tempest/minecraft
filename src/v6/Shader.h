#ifndef V6_SHADER_H
#define V6_SHADER_H

namespace v6 {
  class Shader {
   public:
    Shader ( int );
    void load ( char* );
    void source ( char* );
    int type;
    GLuint shader;
  };
}

#endif
