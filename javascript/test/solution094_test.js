var assert = require('assert');
var solution094 = require('../src/euler/solution094');

describe('Solution094', function() {
  describe('answer', function() {
    it('will answer problem 094', function() {
      assert.equal(solution094.answer(), 518408346);
    });
  });
});