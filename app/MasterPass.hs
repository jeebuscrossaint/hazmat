module MasterPass where

import System.IO
import System.Posix.Terminal
import System.Posix.IO (stdInput)
import System.Console.ANSI

getUserInput :: IO ()
getUserInput = do
  oldSettings <- getTerminalAttributes stdInput
  setTerminalAttributes stdInput (configureTerminal oldSettings) Immediately
  putStrLn "Enter your input: "
  input <- getLimitedInput 128 0 ""
  putStrLn ("\n" ++ input)
  setTerminalAttributes stdInput oldSettings Immediately

configureTerminal :: TerminalAttributes -> TerminalAttributes
configureTerminal attrs = withoutMode (withoutMode attrs ProcessInput) EnableEcho

getLimitedInput :: Int -> Int -> String -> IO String
getLimitedInput 0 _ _ = do
  putStrLn "\nYou've reached the character limit of 128."
  return []
getLimitedInput n count input = do
  eof <- isEOF
  if eof
    then return []
    else do
      char <- getChar
      let newInput = input ++ (char:[])
      cursorUpLine 1
      clearLine
      putStr $ "Characters entered: " ++ show (count + 1)
      cursorDownLine 1
      clearLine
      putStr newInput
      hFlush stdout
      rest <- getLimitedInput (n - 1) (count + 1) newInput
      return (char : rest)

getHashOfInput :: String -> IO ()
getHashOfInput input = do
  