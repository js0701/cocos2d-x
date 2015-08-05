
#ifndef CCGraphicsContext3D_h
#define CCGraphicsContext3D_h

//#include "WebCommon.h"
//#include "WebNonCopyable.h"
//#include "WebString.h"

struct GrGLInterface;


// WGC3D types match the corresponding GL types as defined in OpenGL ES 2.0
// header file gl2.h from khronos.org.
typedef char CCGLchar;
typedef unsigned CCGLenum;
typedef unsigned char CCGLboolean;
typedef unsigned CCGLbitfield;
typedef signed char CCGLbyte;
typedef unsigned char CCGLubyte;
typedef short CCGLshort;
typedef unsigned short CCGLushort;
typedef int CCGLint;
typedef int CCGLsizei;
typedef unsigned CCGLuint;
typedef float CCGLfloat;
typedef float CCGLclampf;
typedef signed long int CCGLintptr;
typedef signed long int CCGLsizeiptr;
typedef void CCGLvoid;


// Typedef for server-side objects like OpenGL textures and program objects.
typedef CCGLuint WebGLId;

// This interface abstracts the operations performed by the
// GraphicsContext3D in order to implement WebGL. Nearly all of the
// methods exposed on this interface map directly to entry points in
// the OpenGL ES 2.0 API.
//
// Creating a WebGraphicsContext does not make it current, or guarantee
// that the context has been created successfully. Use
// makeContextCurrent() to complete initialization of the context, treating
// a false return value as indication that the context could not be created
// successfully.




class CCGraphicsContext3D {
protected:
     static CCGraphicsContext3D* s_GraphicsContext3D ;

public:

     CCGraphicsContext3D()
     {
     }
     virtual ~CCGraphicsContext3D()
     {

     }

	 static CCGraphicsContext3D* get3DContext()
     {
        return s_GraphicsContext3D;
     }

     virtual void setGLContext(void* GLContext)= 0;

    // The entry points below map directly to the OpenGL ES 2.0 API.
    // See: http://www.khronos.org/registry/gles/
    // and: http://www.khronos.org/opengles/sdk/docs/man/
    virtual void activeTexture(CCGLenum texture) = 0;
    virtual void attachShader(WebGLId program, WebGLId shader) = 0;
    virtual void bindAttribLocation(WebGLId program, CCGLuint index, const CCGLchar* name) = 0;
    virtual void bindBuffer(CCGLenum target, WebGLId buffer) = 0;
    virtual void bindFramebuffer(CCGLenum target, WebGLId framebuffer) = 0;
    virtual void bindRenderbuffer(CCGLenum target, WebGLId renderbuffer) = 0;
    virtual void bindTexture(CCGLenum target, WebGLId texture) = 0;
    virtual void blendColor(CCGLclampf red, CCGLclampf green, CCGLclampf blue, CCGLclampf alpha) = 0;
    virtual void blendEquation(CCGLenum mode) = 0;
    virtual void blendEquationSeparate(CCGLenum modeRGB, CCGLenum modeAlpha) = 0;
    virtual void blendFunc(CCGLenum sfactor, CCGLenum dfactor) = 0;
    virtual void blendFuncSeparate(CCGLenum srcRGB, CCGLenum dstRGB, CCGLenum srcAlpha, CCGLenum dstAlpha) = 0;

    virtual void bufferData(CCGLenum target, CCGLsizeiptr size, const void* data, CCGLenum usage) = 0;
    virtual void bufferSubData(CCGLenum target, CCGLintptr offset, CCGLsizeiptr size, const void* data) = 0;

    virtual CCGLenum checkFramebufferStatus(CCGLenum target) = 0;
    virtual void clear(CCGLbitfield mask) = 0;
    virtual void clearColor(CCGLclampf red, CCGLclampf green, CCGLclampf blue, CCGLclampf alpha) = 0;
    virtual void clearDepth(CCGLclampf depth) = 0;
    virtual void clearStencil(CCGLint s) = 0;
    virtual void colorMask(CCGLboolean red, CCGLboolean green, CCGLboolean blue, CCGLboolean alpha) = 0;
    virtual void compileShader(WebGLId shader) = 0;

    virtual void compressedTexImage2D(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLsizei width, CCGLsizei height, CCGLint border, CCGLsizei imageSize, const void* data) = 0;
    virtual void compressedTexSubImage2D(CCGLenum target, CCGLint level, CCGLint xoffset, CCGLint yoffset, CCGLsizei width, CCGLsizei height, CCGLenum format, CCGLsizei imageSize, const void* data) = 0;
    virtual void copyTexImage2D(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLint x, CCGLint y, CCGLsizei width, CCGLsizei height, CCGLint border) = 0;
    virtual void copyTexSubImage2D(CCGLenum target, CCGLint level, CCGLint xoffset, CCGLint yoffset, CCGLint x, CCGLint y, CCGLsizei width, CCGLsizei height) = 0;
    virtual void cullFace(CCGLenum mode) = 0;
    virtual void depthFunc(CCGLenum func) = 0;
    virtual void depthMask(CCGLboolean flag) = 0;
    virtual void depthRange(CCGLclampf zNear, CCGLclampf zFar) = 0;
    virtual void detachShader(WebGLId program, WebGLId shader) = 0;
    virtual void disable(CCGLenum cap) = 0;
    virtual void disableVertexAttribArray(CCGLuint index) = 0;
    virtual void drawArrays(CCGLenum mode, CCGLint first, CCGLsizei count) = 0;
    virtual void drawElements(CCGLenum mode, CCGLsizei count, CCGLenum type, CCGLvoid* offset) = 0;

    virtual void enable(CCGLenum cap) = 0;
    virtual void enableVertexAttribArray(CCGLuint index) = 0;
    virtual void finish() = 0;
    virtual void flush() = 0;
    virtual void framebufferRenderbuffer(CCGLenum target, CCGLenum attachment, CCGLenum renderbuffertarget, WebGLId renderbuffer) = 0;
    virtual void framebufferTexture2D(CCGLenum target, CCGLenum attachment, CCGLenum textarget, WebGLId texture, CCGLint level) = 0;
    virtual void frontFace(CCGLenum mode) = 0;
    virtual void generateMipmap(CCGLenum target) = 0;

    virtual void getActiveAttrib(WebGLId program, CCGLuint index, CCGLsizei *length, CCGLsizei *size,  CCGLenum *type, CCGLchar* name) = 0;
    virtual void getActiveUniform(WebGLId program, CCGLuint index, CCGLsizei *length, CCGLsizei *size, CCGLenum *type, CCGLchar* name) = 0;
    virtual void getAttachedShaders(WebGLId program, CCGLsizei maxCount, CCGLsizei* count, WebGLId* shaders) = 0;
    virtual CCGLint getAttribLocation(WebGLId program, const CCGLchar* name) = 0;
    virtual void getBooleanv(CCGLenum pname, CCGLboolean* value) = 0;
    virtual void getBufferParameteriv(CCGLenum target, CCGLenum pname, CCGLint* value) = 0;
    virtual CCGLenum getError() = 0;
    virtual void getFloatv(CCGLenum pname, CCGLfloat* value) = 0;
    virtual void getFramebufferAttachmentParameteriv(CCGLenum target, CCGLenum attachment, CCGLenum pname, CCGLint* value) = 0;
    virtual void getIntegerv(CCGLenum pname, CCGLint* value) = 0;
    virtual void getProgramiv(WebGLId program, CCGLenum pname, CCGLint* value) = 0;
    virtual void getProgramInfoLog(WebGLId program, CCGLsizei maxLength, CCGLsizei *length, CCGLchar *infoLog) = 0;
    virtual void getRenderbufferParameteriv(CCGLenum target, CCGLenum pname, CCGLint* value) = 0;
    virtual void getShaderiv(WebGLId shader, CCGLenum pname, CCGLint* value) = 0;
    virtual void getShaderInfoLog(WebGLId shader, CCGLsizei maxLength, CCGLsizei *length, CCGLchar *infoLog) = 0;
    virtual void getShaderPrecisionFormat(CCGLenum shadertype, CCGLenum precisiontype, CCGLint* range, CCGLint* precision) = 0;
    virtual void getShaderSource(WebGLId shader, CCGLsizei bufSize, CCGLsizei*  length, CCGLchar * source) = 0;
    virtual CCGLubyte* getString(CCGLenum name) = 0;
    virtual void getTexParameterfv(CCGLenum target, CCGLenum pname, CCGLfloat* value) = 0;
    virtual void getTexParameteriv(CCGLenum target, CCGLenum pname, CCGLint* value) = 0;
    virtual void getUniformfv(WebGLId program, CCGLint location, CCGLfloat* value) = 0;
    virtual void getUniformiv(WebGLId program, CCGLint location, CCGLint* value) = 0;
    virtual CCGLint getUniformLocation(WebGLId program, const CCGLchar* name) = 0;
    virtual void getVertexAttribfv(CCGLuint index, CCGLenum pname, CCGLfloat* value) = 0;
    virtual void getVertexAttribiv(CCGLuint index, CCGLenum pname, CCGLint* value) = 0;
    virtual CCGLsizeiptr getVertexAttribOffset(CCGLuint index, CCGLenum pname) = 0;

    virtual void hint(CCGLenum target, CCGLenum mode) = 0;
    virtual CCGLboolean isBuffer(WebGLId buffer) = 0;
    virtual CCGLboolean isEnabled(CCGLenum cap) = 0;
    virtual CCGLboolean isFramebuffer(WebGLId framebuffer) = 0;
    virtual CCGLboolean isProgram(WebGLId program) = 0;
    virtual CCGLboolean isRenderbuffer(WebGLId renderbuffer) = 0;
    virtual CCGLboolean isShader(WebGLId shader) = 0;
    virtual CCGLboolean isTexture(WebGLId texture) = 0;
    virtual void lineWidth(CCGLfloat) = 0;
    virtual void linkProgram(WebGLId program) = 0;
    virtual void pixelStorei(CCGLenum pname, CCGLint param) = 0;
    virtual void polygonOffset(CCGLfloat factor, CCGLfloat units) = 0;

    virtual void readPixels(CCGLint x, CCGLint y, CCGLsizei width, CCGLsizei height, CCGLenum format, CCGLenum type, void* pixels) = 0;

    virtual void releaseShaderCompiler() = 0;

    virtual void renderbufferStorage(CCGLenum target, CCGLenum internalformat, CCGLsizei width, CCGLsizei height) = 0;
    virtual void sampleCoverage(CCGLclampf value, CCGLboolean invert) = 0;
    virtual void scissor(CCGLint x, CCGLint y, CCGLsizei width, CCGLsizei height) = 0;
    virtual void shaderSource(WebGLId shader, 	CCGLsizei count, const CCGLchar **string, const CCGLint *length) = 0;
    virtual void stencilFunc(CCGLenum func, CCGLint ref, CCGLuint mask) = 0;
    virtual void stencilFuncSeparate(CCGLenum face, CCGLenum func, CCGLint ref, CCGLuint mask) = 0;
    virtual void stencilMask(CCGLuint mask) = 0;
    virtual void stencilMaskSeparate(CCGLenum face, CCGLuint mask) = 0;
    virtual void stencilOp(CCGLenum fail, CCGLenum zfail, CCGLenum zpass) = 0;
    virtual void stencilOpSeparate(CCGLenum face, CCGLenum fail, CCGLenum zfail, CCGLenum zpass) = 0;

    virtual void texImage2D(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLsizei width, CCGLsizei height, CCGLint border, CCGLenum format, CCGLenum type, const void* pixels) = 0;
    virtual void texImage2DHTMLImageElement(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLenum format, CCGLenum type, void*) = 0;
    virtual void texImage2DHTMLCanvasElement(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLenum format, CCGLenum type, void*) = 0;
    virtual void texImage2DHTMLVideoElement(CCGLenum target, CCGLint level, CCGLenum internalformat, CCGLenum format, CCGLenum type, void* pElement) = 0;

    virtual void texParameterf(CCGLenum target, CCGLenum pname, CCGLfloat param) = 0;
    virtual void texParameteri(CCGLenum target, CCGLenum pname, CCGLint param) = 0;

    virtual void texSubImage2D(CCGLenum target, CCGLint level, CCGLint xoffset, CCGLint yoffset, CCGLsizei width, CCGLsizei height, CCGLenum format, CCGLenum type, const void* pixels) = 0;


    virtual void uniform1f(CCGLint location, CCGLfloat x) = 0;
    virtual void uniform1fv(CCGLint location, CCGLsizei count, const CCGLfloat* v) = 0;
    virtual void uniform1i(CCGLint location, CCGLint x) = 0;
    virtual void uniform1iv(CCGLint location, CCGLsizei count, const CCGLint* v) = 0;
    virtual void uniform2f(CCGLint location, CCGLfloat x, CCGLfloat y) = 0;
    virtual void uniform2fv(CCGLint location, CCGLsizei count, const CCGLfloat* v) = 0;
    virtual void uniform2i(CCGLint location, CCGLint x, CCGLint y) = 0;
    virtual void uniform2iv(CCGLint location, CCGLsizei count, const CCGLint* v) = 0;
    virtual void uniform3f(CCGLint location, CCGLfloat x, CCGLfloat y, CCGLfloat z) = 0;
    virtual void uniform3fv(CCGLint location, CCGLsizei count, const CCGLfloat* v) = 0;
    virtual void uniform3i(CCGLint location, CCGLint x, CCGLint y, CCGLint z) = 0;
    virtual void uniform3iv(CCGLint location, CCGLsizei count, const CCGLint* v) = 0;
    virtual void uniform4f(CCGLint location, CCGLfloat x, CCGLfloat y, CCGLfloat z, CCGLfloat w) = 0;
    virtual void uniform4fv(CCGLint location, CCGLsizei count, const CCGLfloat* v) = 0;
    virtual void uniform4i(CCGLint location, CCGLint x, CCGLint y, CCGLint z, CCGLint w) = 0;
    virtual void uniform4iv(CCGLint location, CCGLsizei count, const CCGLint* v) = 0;
    virtual void uniformMatrix2fv(CCGLint location, CCGLsizei count, CCGLboolean transpose, const CCGLfloat* value) = 0;
    virtual void uniformMatrix3fv(CCGLint location, CCGLsizei count, CCGLboolean transpose, const CCGLfloat* value) = 0;
    virtual void uniformMatrix4fv(CCGLint location, CCGLsizei count, CCGLboolean transpose, const CCGLfloat* value) = 0;

    virtual void useProgram(WebGLId program) = 0;
    virtual void validateProgram(WebGLId program) = 0;

    virtual void vertexAttrib1f(CCGLuint index, CCGLfloat x) = 0;
    virtual void vertexAttrib1fv(CCGLuint index, const CCGLfloat* values) = 0;
    virtual void vertexAttrib2f(CCGLuint index, CCGLfloat x, CCGLfloat y) = 0;
    virtual void vertexAttrib2fv(CCGLuint index, const CCGLfloat* values) = 0;
    virtual void vertexAttrib3f(CCGLuint index, CCGLfloat x, CCGLfloat y, CCGLfloat z) = 0;
    virtual void vertexAttrib3fv(CCGLuint index, const CCGLfloat* values) = 0;
    virtual void vertexAttrib4f(CCGLuint index, CCGLfloat x, CCGLfloat y, CCGLfloat z, CCGLfloat w) = 0;
    virtual void vertexAttrib4fv(CCGLuint index, const CCGLfloat* values) = 0;
    //virtual void vertexAttribPointer(CCGLuint index, CCGLint size, CCGLenum type, CCGLboolean normalized,
    //                                 CCGLsizei stride, CCGLintptr offset) = 0;
    virtual void vertexAttribPointer(CCGLuint index, CCGLint size, CCGLenum type, CCGLboolean normalized,
                                     CCGLsizei stride, CCGLvoid* offset) = 0;

    virtual void viewport(CCGLint x, CCGLint y, CCGLsizei width, CCGLsizei height) = 0;

    // Support for buffer creation and deletion.
    virtual void genBuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void genFramebuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void genRenderbuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void genTextures(CCGLsizei count, WebGLId* ids) = 0;

    virtual void deleteBuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void deleteFramebuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void deleteRenderbuffers(CCGLsizei count, WebGLId* ids) = 0;
    virtual void deleteTextures(CCGLsizei count, WebGLId* ids) = 0;

    virtual WebGLId createBuffer() = 0;
    virtual WebGLId createFramebuffer() = 0;
    virtual WebGLId createRenderbuffer() = 0;
    virtual WebGLId createTexture() = 0;

    virtual void deleteBuffer(WebGLId) = 0;
    virtual void deleteFramebuffer(WebGLId) = 0;
    virtual void deleteRenderbuffer(WebGLId) = 0;
    virtual void deleteTexture(WebGLId) = 0;

    virtual WebGLId createProgram() = 0;
    virtual WebGLId createShader(CCGLenum) = 0;

    virtual void deleteShader(WebGLId) = 0;
    virtual void deleteProgram(WebGLId) = 0;

    //Return the canvas width and height to set
    virtual int canvasWidth() = 0;
    virtual int canvasHeight() = 0;

    virtual bool isContextLost() = 0;

    //Added function to support General file read
    virtual unsigned char* getDataFromURL(const char* fileURL, unsigned long* pSize) = 0;

    // Added function to support Cocos2d to load texture from a filename
    virtual void texImage2D(CCGLenum target, CCGLint level, CCGLenum internalformat,
        CCGLenum format, CCGLenum type, const char* urlString, CCGLint *width, CCGLint* height) = 0;

};

//extern CCGraphicsContext3D* s_GraphicsContext3D;

#endif

