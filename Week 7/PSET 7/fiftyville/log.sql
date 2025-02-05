-- Keep a log of any SQL queries you execute as you solve the mystery.

-- first i get the schema from database file

-- 1.See inside the crime_scene_reports table to match the date and location of the crime.
 SELECT description FROM crime_scene_reports
    WHERE year = "2021" AND month = "7" AND day = "28";

-- 2.Check the interview table at the time of the crime and search for witnesses who mention the bakery.
SELECT transcript FROM interviews
    WHERE year = "2021" AND month = "7" AND day = "28" AND transcript LIKE "%bakery%";

-- 3.According to Witness #1, I need the name of the license plate that left the parking lot.
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name
FROM
    people JOIN bakery_security_logs
            ON bakery_security_logs.license_plate = people.license_plate
WHERE
        bakery_security_logs.year = "2021"
    AND bakery_security_logs.month = "7"
    AND bakery_security_logs.day = "28"
    AND bakery_security_logs.hour = "10"
    AND bakery_security_logs.minute >= "15"
    AND bakery_security_logs.minute <= "25";

-- 4.According to Witness #2, I require the name of the individual who withdrew money from an ATM during the occurrence of the crime.
SELECT people.name, atm_transactions.transaction_type
FROM
    people JOIN bank_accounts
            ON bank_accounts.person_id = people.id
           JOIN atm_transactions
            ON atm_transactions.account_number = bank_accounts.account_number
WHERE
        atm_transactions.year = "2021"
    AND atm_transactions.month = "7"
    AND atm_transactions.day = "28"
    AND atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = "withdraw";

-- 5.According to Witness #3
-- 5.1 Check the list of callers and receivers at the time of the crime that call duration of less than 1 minute.

SELECT name, phone_calls.duration
FROM
    people JOIN phone_calls
            ON people.phone_number = phone_calls.caller
WHERE
        phone_calls.year = "2021"
    AND phone_calls.month = "7"
    AND phone_calls.day = "28"
    AND duration <= "60"
    ORDER BY phone_calls.duration;

SELECT name, phone_calls.duration
FROM
    people JOIN phone_calls
            ON people.phone_number = phone_calls.receiver
WHERE
        phone_calls.year = "2021"
    AND phone_calls.month = "7"
    AND phone_calls.day = "28"
    AND duration <= "60"
    ORDER BY phone_calls.duration;


--5.2 Check the list of flights on the earliest flight the following day.
SELECT id, hour ,minute , origin_airport_id, destination_airport_id
FROM flights
WHERE year = "2021" AND month = "7" AND day = "29"
ORDER BY hour ASC
LIMIT 1;

--5.3 Finding city from id
SELECT city FROM airports WHERE id = 8;
SELECT city FROM airports WHERE id = 4;

--I find that destination is New York City

-- 6.Find the passenger on this flight bound for New York City:
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people JOIN passengers
    ON people.passport_number = passengers.passport_number
JOIN flights
    ON passengers.flight_id = flights.id
WHERE
        flights.year = "2021"
    AND flights.month = "7"
    AND flights.day = "29"
    AND flights.hour = "8"
    AND flights.minute = "20"
    ORDER BY passengers.passport_number;

--I noticed that the name "BRUCE" is repeated in those tables.
--Additionally, tables 5.1 indicate that BRUCE had a conversation with ROBIN.




