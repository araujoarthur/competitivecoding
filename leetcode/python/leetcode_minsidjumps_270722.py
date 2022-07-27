# Submission Details: https://leetcode.com/submissions/detail/757770027/ , https://leetcode.com/submissions/detail/757786452/
# 1s Version Submitted 27/07/2022 00:44
# 2nd Version Submitted 27/07/2022 1:10

class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        steps = len(obstacles) - 1
        lanes = [1,2,3]
        currentLane = lanes[1]
        sidejumps = 0
        for stp, obstacle in enumerate(obstacles):
            if stp + 1 > steps: break
            if obstacles[stp + 1] == currentLane:
                sidejumps += 1
                viableJumps = [i for i in lanes if ((i != obstacle) and ( i != currentLane) and (i != obstacles[stp + 1]))]
                print(viableJumps)
                
                if lenViables := len(viableJumps) == 1:
                        currentLane = viableJumps[0]
                else:
                    freeSteps = {i:0 for i in viableJumps}
                    for lane in viableJumps:
                        for stpTaken in range(stp, len(obstacles)):
                            if lane != obstacles[stpTaken]:
                                freeSteps[lane] += 1
                            else:
                                break
                    currentLane = max(freeSteps, key=freeSteps.get)
        return sidejumps

        