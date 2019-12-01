##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cpp_code
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10"
ProjectPath            :="/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code"
IntermediateDirectory  :="/home/acf/Documents/ENPM809Y\ Files/Final_Project/Final_Project_Rachith/FP-Group10"/build-$(ConfigurationName)/__/__/__/__/__/__/__/__
OutDir                 :="/home/acf/Documents/ENPM809Y\ Files/Final_Project/Final_Project_Rachith/FP-Group10"/build-$(ConfigurationName)/__/__/__/__/__/__/__/__
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alex Filie
Date                   :=28/11/19
CodeLitePath           :=/home/acf/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)src/LandBasedRobot $(IncludeSwitch)src/LandBasedTracked $(IncludeSwitch)src/LandBasedWheeled $(IncludeSwitch)src/API $(IncludeSwitch)src/Maze $(IncludeSwitch)src/Direction $(IncludeSwitch)src/Algorithm 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -Wmain -g -O0 -W -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/cpp_code/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/cpp_code"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/cpp_code"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/cpp_code/.d:
	@mkdir -p "../build-$(ConfigurationName)/cpp_code"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix): src/LandBasedRobot/landbasedrobot.cpp ../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/LandBasedRobot/landbasedrobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix): src/LandBasedRobot/landbasedrobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix) -MM src/LandBasedRobot/landbasedrobot.cpp

../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(PreprocessSuffix): src/LandBasedRobot/landbasedrobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_LandBasedRobot_landbasedrobot.cpp$(PreprocessSuffix) src/LandBasedRobot/landbasedrobot.cpp

../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix): src/LandBasedWheeled/landbasedwheeled.cpp ../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/LandBasedWheeled/landbasedwheeled.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix): src/LandBasedWheeled/landbasedwheeled.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix) -MM src/LandBasedWheeled/landbasedwheeled.cpp

../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(PreprocessSuffix): src/LandBasedWheeled/landbasedwheeled.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_LandBasedWheeled_landbasedwheeled.cpp$(PreprocessSuffix) src/LandBasedWheeled/landbasedwheeled.cpp

../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix): src/LandBasedTracked/landbasedtracked.cpp ../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/LandBasedTracked/landbasedtracked.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix): src/LandBasedTracked/landbasedtracked.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix) -MM src/LandBasedTracked/landbasedtracked.cpp

../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(PreprocessSuffix): src/LandBasedTracked/landbasedtracked.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_LandBasedTracked_landbasedtracked.cpp$(PreprocessSuffix) src/LandBasedTracked/landbasedtracked.cpp

../build-$(ConfigurationName)/cpp_code/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/cpp_code/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/cpp_code/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(ObjectSuffix): src/Algorithm/bfsalgorithm.cpp ../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/Algorithm/bfsalgorithm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Algorithm_bfsalgorithm.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(DependSuffix): src/Algorithm/bfsalgorithm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(DependSuffix) -MM src/Algorithm/bfsalgorithm.cpp

../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(PreprocessSuffix): src/Algorithm/bfsalgorithm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_Algorithm_bfsalgorithm.cpp$(PreprocessSuffix) src/Algorithm/bfsalgorithm.cpp

../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(ObjectSuffix): src/API/api.cpp ../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/API/api.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_API_api.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(DependSuffix): src/API/api.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(DependSuffix) -MM src/API/api.cpp

../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(PreprocessSuffix): src/API/api.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_API_api.cpp$(PreprocessSuffix) src/API/api.cpp

../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(ObjectSuffix): src/Maze/maze.cpp ../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/acf/Documents/ENPM809Y Files/Final_Project/Final_Project_Rachith/FP-Group10/cpp_code/src/Maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Maze_maze.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(DependSuffix): src/Maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(DependSuffix) -MM src/Maze/maze.cpp

../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(PreprocessSuffix): src/Maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/cpp_code/src_Maze_maze.cpp$(PreprocessSuffix) src/Maze/maze.cpp


-include ../build-$(ConfigurationName)/cpp_code//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


