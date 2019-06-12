#include "pch.h"

TEST(AddObserver, Try_to_attach_nullptr_object) {
	Progress p;
	ProgressObserver *obs = nullptr;

	EXPECT_EQ(p.AddObserver(obs), false);
}

TEST(AddObserver, Try_to_attach_correct_object) {
	Progress p;
	ProgressObserver pObs;

	EXPECT_EQ(p.AddObserver(&pObs), true);
}

TEST(RemoveObserver, Try_to_detach_nullptr_object) {
	Progress p;

	EXPECT_EQ(p.RemoveObserver(nullptr), false);
}

TEST(RemoveObserver, Try_to_detach_attached_object) {
	Progress p;
	ProgressObserver pObs;
	p.AddObserver(&pObs);

	EXPECT_EQ(p.RemoveObserver(&pObs), true);
}

TEST(RemoveObserver, Try_to_detach_not_attached_object) {
	Progress p;
	ProgressObserver pObs;

	EXPECT_EQ(p.RemoveObserver(&pObs), true);
}

TEST(SetProgressValue, negative) {
	Progress p;

	EXPECT_EQ(p.SetProgressValue(-1), false);
}

TEST(SetProgressValue, zero) {
	Progress p;

	EXPECT_EQ(p.SetProgressValue(0), true);
}

TEST(SetProgressValue, positive) {
	Progress p;

	EXPECT_EQ(p.SetProgressValue(10), true);
}

TEST(SetEndProgressValue, negative) {
	Progress p;

	EXPECT_EQ(p.SetEndProgressValue(-1), false);
}

TEST(SetEndProgressValue, zero) {
	Progress p;

	EXPECT_EQ(p.SetEndProgressValue(0), true);
}

TEST(SetEndProgressValue, positive) {
	Progress p;

	EXPECT_EQ(p.SetEndProgressValue(10), true);
}

TEST(CopyFiles, wrong_file_path) {
	Progress p;
	std::vector<std::string> fileNames = { "", "", "" };

	EXPECT_EQ(CopyFiles(fileNames, &p), false);
}

TEST(CopyFiles, wrong_progress_object) {
	Progress *p = nullptr;

	std::vector<std::string> fileNames = { "The_Hardkiss_Stones.mp3", "The_Hardkiss_Stones.mp3", "The_Hardkiss_Stones.mp3" };

	EXPECT_EQ(CopyFiles(fileNames, p), false);
}

TEST(CopyFiles, correct_objects_not_correct_number_child_progresses) {
	Progress p;
	std::vector<std::string> fileNames = { "The_Hardkiss_Stones.mp3", "The_Hardkiss_Stones.mp3", "The_Hardkiss_Stones.mp3" };

	EXPECT_EQ(CopyFiles(fileNames, &p), false);

}

TEST(GetFileSize, not_correct_fstream_object) {
	int a, b;
	std::ifstream fin("", std::ios::in | std::ios::binary);

	EXPECT_EQ(GetFileSize(fin, a, b), false);
}

TEST(GetFileSize, correct_fstream_object_not_correct_number_child_progresses) {
	int a, b;
	std::ifstream fin("The_Hardkiss_Stones.mp3", std::ios::in | std::ios::binary);

	EXPECT_EQ(GetFileSize(fin, a, b), false);

	fin.close();
}


/*int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}*/