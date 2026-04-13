var assert = require('assert');
var solution083 = require('../src/euler/solution083');

describe('Solution083', function() {
  describe('answer', function() {
    it('will answer problem 083', function() {
      assert.equal(solution083.answer(), 425185);
    });
  });
});