{-
    Test if a giver number is a Prime or not.
    I even do not know if this work, but at least I tried.
-}
isPrime :: Integer -> Bool
isPrime number = "The number:" ++ show number ++ "is a Prime number? " ++ show result ++ "."
    where result = if number < 2 || number `mod` 2 == 0 && number > 2 then False else length (filter (\denominator -> number `mod` denominator == 0) [2..number/2]) < 2


{-
    This one was made by ChatGPT
-}
IsPrime :: Int -> Bool
IsPrime number
  | number < 2 || (number `mod` 2 == 0 && number > 2) = False
  | otherwise = length (filter (\denominator -> number `mod` denominator == 0) [1..(number `div` 2)]) < 2
