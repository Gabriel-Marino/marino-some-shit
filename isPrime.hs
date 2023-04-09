{-
    Test if a giver number is a Prime or not.
-}
isPrimeS :: Integer -> String
isPrimeS number = "\n The number: " ++ show number ++ " is a Prime number? " ++ show result ++ "."
    where result = if number < 2 || number `mod` 2 == 0 && number > 2 then False else length (filter (\denominator -> number `mod` denominator == 0) [2..number `div` 2]) < 2

isPrimeB :: Integer -> Bool
isPrimeB number = if number < 2 || number `mod` 2 == 0 && number > 2 then False else length (filter (\denominator -> number `mod` denominator == 0) [2..number `div` 2]) < 2

{-
    This one was made by ChatGPT
-}
isPrimeGPT :: Integer -> Bool
isPrimeGPT number
  | number < 2 || (number `mod` 2 == 0 && number > 2) = False
  | otherwise = length (filter (\denominator -> number `mod` denominator == 0) [1..(number `div` 2)]) < 2


{-
    mapM_ print(map isPrimeS [1..1000])
    mapM_ print(filter isPrimeB [1..1000])
-}