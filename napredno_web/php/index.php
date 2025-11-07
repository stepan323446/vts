<?php
declare(strict_types=1);

/**
 * @var int[] $numbers
 */
$numbers = [3, 5, 6, 1, 3];

/**
 * smallest number from array
 * @param int[] $nums
 * @return int
 */
function getMinValue(array $nums): int {
    return min($nums);
}
/**
 * biggest number from array
 * @param int[] $nums
 * @return int
 */
function getMaxValue(array $nums): int {
    return max($nums);
}
/**
 * Sum and average num from array
 * @param int[] $nums
 * @return string
 */
function getSumAndAverage(array $nums): string {
    $sum = array_sum($nums);
    $count = count($nums);
    $average = $sum / $count;

    return <<< EOT
Sum: $sum
Average: $average
EOT;
}

echo getMinValue($numbers);
echo '<br>';

echo getMaxValue($numbers);
echo '<br>';

echo getSumAndAverage($numbers);
echo '<br>';