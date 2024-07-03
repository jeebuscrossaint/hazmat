module MasterPass where

import System.IO
import System.Posix.Terminal
import System.Posix.IO (stdInput)

getUserInput :: IO ()
getUserInput = do
  oldSettings <- getTerminalAttributes stdInput
  setTerminalAttributes stdInput (configureTerminal oldSettings) Immediately
  putStrLn "Enter your input: "
  input <- getLimitedInput 128 0
  putStrLn ("\n" ++ input)
  setTerminalAttributes stdInput oldSettings Immediately

configureTerminal :: TerminalAttributes -> TerminalAttributes
configureTerminal attrs = withoutMode (withoutMode attrs ProcessInput) EnableEcho

getLimitedInput :: Int -> Int -> IO String
getLimitedInput 0 _ = do
  putStrLn "\nYou've reached the character limit of 128."
  return []
getLimitedInput n count = do
  eof <- isEOF
  if eof
    then return []
    else do
      char <- getChar
      putStr $ "\rCharacters entered: " ++ show (count + 1)
      hFlush stdout
      rest <- getLimitedInput (n - 1) (count + 1)
      return (char : rest)

