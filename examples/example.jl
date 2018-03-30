function recursive(x::Int)
    println(x)
    if x > 0
        recursive(x-1)
    end
end

recursive(9)