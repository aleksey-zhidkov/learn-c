var cmd = StringBuilder("./ex10")

var i = 0
while (i < 2000000) {
	cmd.append(" arg").append(i++)
}

val c = cmd.toString()
println("Executing")
val proc = Runtime.getRuntime().exec(c)
proc.inputStream.reader().forEachLine { println(it.toString()) }