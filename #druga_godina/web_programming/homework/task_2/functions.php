<?php

interface Select {
    function render(): void;
    function setDefaultValue(string|int $value): void;
}

/**
 * Default <select> for array display
 */
class SelectArray implements Select {
    protected string $name;
    protected string $defaultValue = "";
    protected string $id;
    protected string $label;
    protected array $array;
    protected bool $key;

    /**
     * Constructor for creating a select field object with options from an array.
     * @param string $name  The name attribute of the select field.
     * @param string $id    The ID attribute of the select field.
     * @param string $label The label text for the select field.
     * @param array $array An array of options to populate the select field.
     * @param bool $key   Whether to use array keys as option values (default: false).
     */
    function __construct(string $name, string $id, string $label, array $array, bool $key = false) {
        $this->id = $id;
        $this->name = $name;
        $this->label = $label;
        $this->array = $array;
        $this->key = $key;
    }

    /**
     * Renders the HTML <select> element with options from the provided array.
     * @return void
     */
    function render(): void {
        ?>
        <label for="<?php echo $this->id ?>">
            <?php echo $this->label ?>
        </label>
        
        <select id="<?php echo $this->id ?>" name="<?php echo $this->name ?>">
            <option value="">Choose</option>

            <?php
            foreach($this->array as $k => $v) {
                // Choose value for option
                $option_value = $v;
                
                if($this->key)
                    $option_value = $k;

                // Attribute selected for some value
                $attributes = "";
                if($option_value == $this->defaultValue) {
                    $attributes .= 'selected';
                }

                ?>
                <option value="<?php echo $option_value ?>" <?php echo $attributes ?>>
                    <?php echo htmlspecialchars($v); ?>
                </option>
                <?php
            }
            ?>

        </select>
        <?php
    }
    
    /**
     * Sets the default selected value for the <select> field.
     *
     * This value will be pre-selected when rendering the dropdown.
     *
     * @param string|int $value The value to be set as default.
     * @return void
     */
    function setDefaultValue(string|int $value): void {
        $this->defaultValue = $value;
    }
}

class SelectNumber extends SelectArray {
    protected int $start;
    protected int $end;

    /**
      * Constructor for creating a select field object with options using range from $start to $end.
     * @param string $name The name attribute of the select field.
     * @param string $id The ID attribute of the select field.
     * @param string $label The label text for the select field.
     * @param int $start The number to start range
     * @param int $end The number to end range
     */
    function __construct(string $name, string $id, string $label, int $start, int $end) {
        if($start > $end)
            [$start, $end] = [ $end, $start ];

        $this->start = $start;
        $this->end = $end;

        $array = [];
        for($i = $start; $i <= $end; $i++) {
            $array[] = $i;
        }

        parent::__construct($name, $id, $label, $array);
    }
}