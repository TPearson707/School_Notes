## CoSc 472 Network & Security - Chapter 1 

## START

## Aim of Course

   * Our focus is on Internet Security
     - which sonsists of measures to deter, prevent, detect, and correct security violations that
       involve the transmission & storage of information     

## Main Points

   * What's Network Security 
   * Security Threats
   * Security Architecture
   * Security Attacks
   * Security Services
   * Security Mechanisms
   * Network Security Models

## Background
  
   * Information Security reqs have changed in recent times
   * Traditionally provided by physical and admin mechanisms
   * *Computer use* requires automated tools to protect files and other stored information
   * *Use of network and communication* links requires measures to protect data during transmission

## Security
  
   * Information Security -
     - is about how to prevent attacks, or failing that, to detect attacks on information-based systems
   * Computer Security -
     - Generic name for the collection of tools designed to protect data and to thwart hackers
   * Network Security -
     - measures to protect data during their transmission
   * Internet Security:
     - measures to protect data during their transmission over a collection of interconnected networks

## Computer Security
    
   * Protection given to an automated info system to attain the applicable objectives of preserving the      **integrity, availability and confidentiality** of info system resources.
     (hardware, software, firmware, information/data, and telecommunicatoins)

## CIA Triad 

                       *

                      Data
Confidentiality        &          Integrity
                    Services 

                   *       *
                  Availability

   * Confidentiality
     - Data Confidentiality -
       - confidential info shouldn't be accessible by unauthorized users
     - Privacy
       - individuals control what info is related to them
   * Integrity
     - Data Integrty -
       - data may only be modified through an authorized mechanism
     - System Integrity -
       - system performs intended function
   * Availability
     - authorized users should be able to access data for legitimate purposes as necessary
    
## Computer Security Challenges

   * Not simple
   * Must consider potntial attacks
   * Procedures used counter-intuitive
   * Involve algorithms and secret info
   * Must decide where to deploy mechanisms 
   * Battle of wits between attackers / admin
   * Not perceived on benefit until fails
   * Requires regular monitoring
   * Too often an after-thought
   * Regarded as impediment to using system

## Computer Security vs. Network Security

   * Computer Security
     - deals with protecting a single machine
   * Network Security
     - deals with protecting the communication of all participants in it
       - Goal of networking is to enable communication at all times and in all scenarios!

## Threats & Attacks
   
   * Threat
     - a potential ofr violatoin of security; a possible danger that might exploit a vulnerability
   * Attack
     - an assault on system security that derives from an intelligent threat

## What Are the Threats?
    
   * No one should be able to attack my computer

   * Hackers
     - Break a password or sniff it off the network
     - Exploit a vulnerability
     - Use **social engineering** Ex. phishing
     - Impersonate someone I trust
     - Viruses & worms
   * Vulnerability
     - A vulernability is a bug in software that creates unexpected computer behavior when exploited.
       - Examples Include
         - enabling access without login
         - running unauthorized code
         - crashing the computer
   * Exploit
     - An exploit is an input to the buggy program that makes use of the existing vulnerability.

    -----------------------------------------------------------------------------------------------
    
   * Types of Attacks

   * Denial-of-Service Attacks (DOS)
     - Aims to disrupt service by either exploiting a vuln or by overloading the server with messsage
   
   * Viruses & worms
    
   * Virus
     - A self-replicating program that requires user ction to activate
       - Such as clicking on an E-mail, downloading an infected file or inserting an infected floppy,
         CD, etc ..

   * Worm
     - A self-replicating program that does not require user action to activate
     - It propagates itself over the network, infects any vulnerable machine it finds and then spreads         from it further

## How to prevent threats
   
   * Prevent break-ins
   * Utilize cryptography to detect tampering
   * Replicate data to recover from tampering
    
   * IP Spoofing
     - putting a fake IP address in the sender field of the IP packets

### Security Architecture

    * Security Attack
      - Any action that compromises the security of information
    * Security Mechanism
      - A mechanism that is designed to detect, prevent, or recover from a security attack
    * Security Service
      - A service that enhances the security of data processing systems and information transfers
      - A security servce makes use of one or more security mechanisms

## Passive & Active Attacks

   * Passive Attack
     - Attempts to learn or make use of informatoin from the system but does not affect system resource
     - Release of the message contents
       - read the contens of the message
     - Traffic analysis
       - observe the pattern of the message    
   * Active Attack:
     - Attemps to alter system resources or affect their operation
     - Masquerade
       - One entity pretends to be a different entity
     - Replay
       - Involves the passive capture of a data unit and its subsequent retransmission to produce an
         unauthorized effect
     - Modification of message
       - A  portion of a legitimate message is altered, or messages are delayed or reordered
     - Denial of Service
       - Prevents or inhibits the normal use or management of communications facilities

## Security Attacks
   
   * Interruption
     - This is an attack on availability
   * Interception
     - This is an attack on confidentiality
   * Modification
     - This is an attack on integrity
   * Fabrication
     - This is an attack on authenticity

## Security Mechanism

    * Feature designed to detect, prevent, or recover from a security attack
      - Cryptography techniques

## Specific & Pervasive Security Mechanisms

   * Specific Security Mechanisms
     - May be incorporated into the appropriate protocol layer in order to provide some OSI
        (Open System Interconnection) security services
     - Include
       - encipherment 
       - digital signatures
       - access controls
       - data integrity
       - authentication exchange
       - traffic padding 
       - routing control
       - notarization
   * Pervasive Security Mechanisms
     - Mechanisms that are not specific to any particular OSI security service or protocol layer
     - Include
       - trusted functionality
       - security labels
       - event detecgtion
       - security audit trails
       - security recovery

# Specific

  * Encipherment
    - The user of mathematical algorithms to transform data into a form that is not readily
      intelligible
    - The transformation and subsequence recovery of the data depend on an algorithm and zero
      or more encryption keys
  * Digital Signatures
    - Data appended to, or a cryptographic transformation of, a data unit that allows recipient
      of the data unit to prove the source and integrity of the data unit and protect against
      forgery (e.g. by the recipient)
  * Access Controls
    - A variety of mechanisms that enforce access rights to resources
  * Data Integrity
    - A variety of mechanisms that enforce access rights to resources
  * Authentication exchange
    - A mechanism inteded to ensure the identity of an entity by means of information exchange
  * Traffic Padding
    - The insertion of bits into gaps in a data stream to frustrate traffic analysis attempts
  * Routing Control
    - Enable selection of particular physically secure routes for certain data and allows routing
      changes, especially when a breach of security is supected.
  * Notarization
    - The use of a trusted third party to assure certain properties of a data exchange

# Pervasive
    
  * Trusted Functionality
    - Perceived to be correct with respect to some criteria (e.g. as established by security policy)
  * Security Labels
    - Marking bound to a resource (where may be a data unit) that names or designates the security 
        attributes of that resource
  * Event Detection
    - Detection of security relevant events
  * Security Audit Trails
    - Data collected and potentially used to facilitate a security audit, which is an independent
        review and examination of system records and activities.
  * Security Recovery
    - Deals with requests from mechanisms, such event handling and management functions, and takes
        recovery actions

### Security Services

    * X.800
      - "a service provided by a protocol layer of communicating open systems, which ensures adequate
        security of the systems or of data transfers"

## Security Services (X.800)

   * Authentication
     - Assurance htat the communicating entity is the one claimed

     - Peer Entity Authentication
       - used in associated with logical connection to provice confidence in the identity of entities
         connected
     - Data-Origin Authentication
       - in a connection transfer, provides assurance that the source of received data is as claimed
   
   * Access Control
     - prevention of the unathorized use of a resource
       - (i.e., this service controls who can have access to a resource, under what conditions access
         can occur, and what those accessing the resource are allowed to do)

# Data Confidentiality

  * Data Confidentiality
    - The protection of data from unauthorized disclosure
  
  * Types of Data Confidentiality
    - Connection Confidentiality 
      - Protection of all user data on a connection
    - Connectionless Confidentiality
      - The protection of all user in a single data block
    - Selective-Field Confidentiality
      - Confidentialy of selected fields within the user data on connection or in a single block
    - Traffic-Flow Confidentiality
      - Protection of information that might be derived from seeing traffic flows

# Data Integrity

  * Data Integrity
    - The assurance that data received are exactly as sent by an authorized entity

  * MIDR
    - Modification, Insertion, Deletion, or Replay

  * Types of Data Integrity
    - Connection Integrity with recovery
      - Provides for the integrity of all user data on a connection and detects any MIDR of the data
        within an entire data sequence, with recovery attempted
    - Connection Integrity without recovery
      - As connectoin integrity with recovery but provides only detection without recovery
    - Selective Field Connection Integrity
      - Provides for the integrity of selected fields within user data of a data block transferred
        over a connection
      - Determines whether the selected fields have any MIDR
    - Connectionless Integrity
      - Provides for the itegrity of selected fields within user data of a data block transferred
        conection and takes the form of determination of whether the selected fields have any MIDR
    - Selection-field Connectionless Integrity
      - Provides for the integrity of selected fields within a single connectionless data block
      - Determines whether selected fields have been modified

# Non-Repudiation

  * Non-Repudiation
    - Protection against denial by one of the entities involved in a communication of having
        participatedd in communication

  * Types of Non-Repudiation
    - Origin Non-Repudiation
      - Proof that the message was sent by specific party
    - Destination Non-Repudiation
      - Proof that the message was received by specific party 

# Availability
  
  * Availability
    - System or System resource accessible and usable on demand by authorized user
