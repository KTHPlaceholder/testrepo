-- No IO, use ghci to test this

main = do
	putStrLn "List of euler totient values for the first 30 integers"
	putStrLn $ show $ [eulerTotient i | i <- [1..30]] 

eulerTotient :: Integer -> Int
eulerTotient n = length [i | i <- [1..n-1], coprime n i]

coprime :: Integer -> Integer -> Bool
coprime a b = euclid a b == 1

euclid :: Integer -> Integer -> Integer
euclid a b 
	| b == 0 = a
	| otherwise = euclid b (mod a b)

