<?php
/**
 * User class to create object
 */
class User {
    const DEFAULT_CITY = "Subotica";
    public static int $userCount = 0;

    public string $username;
    public string $firstname;
    public string $lastname;

    private string $email;
    private int $age;
    private string $school;
    private array $skills;
    private string $studyProgram;
    private string $city;

    protected array $displayDataFields = ['age', 'email', 'school', 'studyProgram'];

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
        string $programm = "Informatics", 
        string $city = self::DEFAULT_CITY
    ) {
        $this->username = $username;
        $this->firstname = $firstname;
        $this->lastname = $lastname;
        $this->email = $email;
        $this->age = $age;
        $this->school = $school;
        $this->skills = $skills;
        $this->studyProgram = $programm;
        $this->city = $city;

        static::$userCount++;
    }

    /**
     * Number of users
     * @return int
     */
    static function getUserCount(): int {
        return static::$userCount;
    }

    /**
     * Returns the full name of the user in the format 'Firstname Lastname'.
     * @return string
     */
    function getName(): string {
        return $this->firstname . " " . $this->lastname;
    }

    /**
     * Updates the user's email address.
     * @param string $email
     * @return void
     */
    function setEmail(string $email): void {
        $this->email = $email;
    }

    /**
     * Validates the email address format and returns a textual message indicating whether it is valid or not.
     * @return string
     */
    function validateEmail(): string {
        if(filter_var($this->email, FILTER_VALIDATE_EMAIL))
            return "Email address is valid";
        
        return "Email address is invalid";
    }

    /**
     * Displays the user's skills, each on a separate line.
     * @return void
     */
    function showSkills(): void {
        ?>
        <div class="skills">
            <?= join("<br>", $this->skills); ?>
        </div>
        <?php
    }

    /**
     * Displays the user's data: age, email, school, and study program in HTML format.
     * @return void
     */
    function showUserData(): void {
        ?>
        <table>
            <thead>
                <tr>
                    <th>Property</th>
                    <th>Value</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach($this->displayDataFields as $field): ?>
                <tr>
                    <td><?= $field ?></td>
                    <td><?= htmlspecialchars((string)$this->{$field}) ?></td>
                </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
        <?php
    }
}