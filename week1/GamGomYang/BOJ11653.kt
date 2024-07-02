fun main() {
    val number = readLine()!!.toInt()
    var n = number
    var i = 2

    while (n > 1) {
        if (n % i == 0) {
            n /= i
            println(i)
            i = 2
        } else {
            i += 1
        }
    }
}
