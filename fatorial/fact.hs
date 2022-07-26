{-
    This function calculates the factorial of a numner num
    and return the string interpolated "The factorial of $num is $result"
-}
factorial :: Integer -> String
factorial num = "The factorial of " ++ show num ++ " is " ++ show result ++ "."
    where result = product [1..num]

main =
   mapM_ print (map factorial [1..1000])

{-
    This function calculates the factorial of a number number
    and return the factorial of the number
-}
fact :: Integer -> Integer
fact number = product[1..number]

{-
    This function receive a number, calculates the factorial with fact
    and return the string interpolated "The factorial of $num is $result"
-}
factorial2 :: Integer -> String
factorial2 num = "The factorial of " ++ show num ++ " is " ++ show fact num ++ "."