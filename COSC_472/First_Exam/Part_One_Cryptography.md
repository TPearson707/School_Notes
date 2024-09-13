## CoSc 472 - Cryptography

## Part One: Cryptography
   * Chapter 2
     - Symmetric Encryption and message confidentiality
   * Chapter 3
     - Public-key cryptography and message authentication

## Main Points
   
   * Cryptography System
     - Symmetric Key
     - Asymmetric Key
     - Hash Functions
   * Security Attacks
     - Brute-force
     - Cryptanalytic
     - Man-in-Middle

## What is Cryptography
   
   * Goal
     - Protect private communication in the public world (CONFIDENTIALITY)
   * How it works
     - Scramble message so that unauthorized users cannot understand the message

## Cryptography is also useful for

   * Authentication
     - Bob should be able to verify that Alice has created the message
   * Integrity Checking
     - Bob should be able to verify that message has not been modified
   * Non-repudiation
     - Alice cannot deny that she indeed sent the messages

## Cryptographic Techniques
   
   * Substitution
     - Goal
       - Obscure relationship between laintext and ciphertext (confusion)
     - each element in the plaintext mapped into naother element
   * Transposition/Shuffling
     - Goal
       - Dissipate redundancy of the plaintext by spreading it over cipertext (diffusion)
     - Elements in the plaintext are rearranged

# Substitution
  
  * Monoalphabetic - each character is replaced with another character

# Transposition
  
  * Shuffle characters in mesage

## Terminology
   
   * Plaintext
     - This is the original message or data that is fed into the algorithm as input
   * Encryption Algorithm
     - Performs substitutions and transformations on plaintext
   * Key
     - input to algorithm, exact sub and transformations performed by algorithm depend on key
   * Ciphertext
     - scrambled message produced as output
       - depends on plaintext and key

   * M = message, plaintext
   * K1 = encryption key
   * Ek1(M) = message M is encrypted using key K1
   * C = ciphertext
   * K2 = decryption key
   * Dk2(C) = ciphertext C is decrypted using key K2
   * if K1 = K2 this is **symmetric (secret key) encryption**
   * if K1 != K2 this is **asymmetric (public key) encyption**


       

