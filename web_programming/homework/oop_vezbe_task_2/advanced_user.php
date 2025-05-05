<?php
require_once("user.php");

/**
 * User class to create object with advanced fields
 */
class AdvancedUser extends User {
    private string $githubProfile;

    /**
     * Constructs a new User instance with the given personal and academic details.
     *
     * @param string $username     The unique username of the user.
     * @param string $firstname    The user's first name.
     * @param string $lastname     The user's last name.
     * @param string $email        The user's email address.
     * @param int    $age          The user's age.
     * @param string $school       The name of the school or institution the user attends.
     * @param string[] $skills     An array of the user's skills (e.g., programming languages, tools).
     * @param string $githubProfile The user's link to github profile.
     * @param string $programm      The user's study program (e.g., Informatics, Mechatronics).
     * @param string $city         The city where the user resides. Defaults to "Subotica".
     */
    function __construct(
        string $username, 
        string $firstname, 
        string $lastname, 
        string $email, 
        int $age, 
        string $school, 
        array $skills,
        string $githubProfile,
        string $programm = "Informatics", 
        string $city = "Subotica"
    ) {
        $this->githubProfile = $githubProfile; 

        parent::__construct($username, $firstname, $lastname, $email, $age, $school, $skills, $programm, $city);
    }

    /**
     * Return github profile link
     * @return string
     */
    function getGithubProfile():string {
        return $this->githubProfile;
    }
}

