x::Int = 10

function func(x::Int, y::Bool, z::Int)
    println("The value of the parameter x is ", x)
    println("The value of the parameter y is ", y)
    println("The value of the parameter z is ", z)
end


func(x+1000, false, true)
println("The value of x is ", x)

#=Prints

The value of the parameter x is 1010
The value of the parameter y is false
The value of the parameter z is 1
The value of x is 10

=#