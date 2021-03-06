﻿using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SimpleFTP.Tests
{
    [TestClass]
    public class FTPTests
    {
        private Server server;
        private Client client;
        private readonly string path = "../../../../SimpleFTP.Tests/test";
        private readonly WriteForTests writeable = new WriteForTests();

        [TestInitialize]
        public void Initialize()
        {
            server = new Server(8888, writeable);
            server.Process();
            client = new Client();
            client.Connect(8888, "localhost");
        }

        [TestMethod]
        public async Task ListTest()
        {
            var listResponse = await client.List(path);
            var expected = $"1 {path}" + "\\" + "file.txt False ";
            Assert.AreEqual(expected, listResponse);
            server.Cancel();
            client.Close();
        }

        [TestMethod]
        public async Task GetTest()
        {
            var getResponse = await client.Get($"{path}/file.txt");
            var expected = "44 Is this the real life? Is this just fantasy?";
            Assert.AreEqual(expected, getResponse);
            server.Cancel();
            client.Close();
        }

        [TestMethod]
        public async Task WrongPathListTest()
        {
            var listResponse = await client.List(path + "/test");
            var expected = "-1 ";
            Assert.AreEqual(expected, listResponse);
            server.Cancel();
            client.Close();
        }

        [TestMethod]
        public async Task WrongPathGetTest()
        {
            var getResponse = await client.Get(path + "/test");
            var expected = "-1 ";
            Assert.AreEqual(expected, getResponse);
            server.Cancel();
            client.Close();
        }
    }
}
