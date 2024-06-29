.class public output
.super java/lang/Object
.method public <init>()V
aload_0
invokenonvirtual java/lang/Object/<init>()V
return
.end method
.method public static output_int(I)V
.limit locals 5
.limit stack 5
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0  ; the argument to function
invokevirtual java/io/PrintStream/print(I)V
return
.end method

.method public static output_float(F)V
.limit locals 5
.limit stack 5
getstatic java/lang/System/out Ljava/io/PrintStream;
fload 0  ; the argument to function
invokevirtual java/io/PrintStream/print(F)V
return
.end method
.method public static output_str(Ljava/lang/String;)V
.limit locals 5
.limit stack 5
getstatic java/lang/System/out Ljava/io/PrintStream;
aload 0
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
return
.end method
.method public static outputln()V
.limit locals 5
.limit stack 5
getstatic java/lang/System/out Ljava/io/PrintStream;
invokevirtual java/io/PrintStream/println()V
return
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 8
.limit stack 1
istore 0
ldc 10
istore 0
iload 0
ldc 3
add
istore 0
iload 0
invokestatic output/Verb/output_int(I)V
ldc 0
ireturn
return
.end method